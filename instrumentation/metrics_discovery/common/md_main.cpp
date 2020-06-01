/*****************************************************************************\

    Copyright © 2019, Intel Corporation

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.

    File Name:  md_main.cpp

    Abstract:   Metrics Discovery main file

\*****************************************************************************/
#include "metrics_discovery_api.h"
#include "md_metrics.h"
#include "md_exports.h"
#include "md_internal.h"
#include "md_per_platform_preamble.h"
#include "md_utils.h"

// Global handle to MetricsDevice
CMetricsDevice* g_MetricsDevice      = NULL;
uint32_t        g_mdRefCounter       = 0;
void*           g_OpenCloseSemaphore = NULL;

TCompletionCode CreateObjectTreeFromFile( const char* fileName, IMetricsDevice_1_5** metricsDevice )
{
    TCompletionCode retVal = CC_OK;

    MD_CHECK_PTR_RET( g_MetricsDevice, CC_ERROR_GENERAL );

    retVal = g_MetricsDevice->OpenFromFile( fileName, MD_IS_INTERNAL_BUILD );
    if( retVal == CC_OK )
    {
        *metricsDevice = g_MetricsDevice;
    }
    else
    {
        if( !g_mdRefCounter )
        {
            MD_SAFE_DELETE( g_MetricsDevice );
        }
        *metricsDevice = NULL;
    }

    return retVal;
}

TCompletionCode SaveObjectTreeToFile( const char* fileName, IMetricsDevice_1_5* metricsDevice )
{
    TCompletionCode retVal = CC_OK;

    g_MetricsDevice = static_cast<CMetricsDevice*>(metricsDevice);
    if( g_MetricsDevice == NULL ) return CC_ERROR_INVALID_PARAMETER;

    retVal = g_MetricsDevice->SaveToFile(fileName);

    return retVal;
}

#ifdef __cplusplus
    extern "C" {
#endif

TCompletionCode OpenMetricsDevice( IMetricsDevice_1_5** metricsDevice )
{
    MD_LOG_ENTER();
    TCompletionCode retVal = CC_OK;

    if( metricsDevice == NULL )
    {
        MD_LOG(LOG_DEBUG, "NULL metrics device");
        MD_LOG_EXIT();
        return CC_ERROR_INVALID_PARAMETER;
    }

    // Init driver interface if needed
    CDriverInterface *pDriverInterface = GetDriverIfc();
    if( !pDriverInterface )
    {
        MD_LOG(LOG_ERROR, "failed to get driver interface");
        MD_LOG_EXIT();
        return CC_ERROR_NOT_SUPPORTED;
    }

    if( pDriverInterface->GetNeedSupportEnable() )
    {
        MD_LOG(LOG_INFO, "driver support enabling...");
        retVal = pDriverInterface->SendSupportEnableEscape(true);
        if( retVal != CC_OK )
        {
            MD_LOG(LOG_ERROR, "driver support enabling failed");
            MD_LOG_EXIT();
            return retVal;
        }
    }

    retVal = GetOpenCloseSemaphore( &g_OpenCloseSemaphore );
    if( retVal != CC_OK )
    {
        MD_LOG(LOG_ERROR, "get semaphore failed");
        MD_LOG_EXIT();
        return retVal;
    }

    if( g_MetricsDevice != NULL )
    {
        *metricsDevice  = g_MetricsDevice;
        retVal          = CC_ALREADY_INITIALIZED;
        g_mdRefCounter++;
    }
    else
    {
        
        g_MetricsDevice = new (std::nothrow) CMetricsDevice();
        if( g_MetricsDevice == NULL )
        {
            retVal = CC_ERROR_NO_MEMORY;
        }
        else
        {
            retVal = CreateMetricTree( g_MetricsDevice );
        }
        if( retVal == CC_OK )
        {
            g_mdRefCounter++;
            *metricsDevice  = g_MetricsDevice;
        }
    }

    ReleaseOpenCloseSemaphore( &g_OpenCloseSemaphore );
    MD_LOG_EXIT();
    return retVal;
}

TCompletionCode CloseMetricsDevice( IMetricsDevice_1_5* metricsDevice )
{
    MD_LOG_ENTER();
    TCompletionCode   retVal           = CC_OK;
    CDriverInterface* pDriverInterface = GetDriverIfc();
    if( !pDriverInterface )
    {
        MD_LOG(LOG_ERROR, "failed to get driver interface");
        MD_LOG_EXIT();
        return CC_ERROR_NOT_SUPPORTED;
    }

    retVal = GetOpenCloseSemaphore( &g_OpenCloseSemaphore );
    if( retVal != CC_OK )
    {
        MD_LOG(LOG_ERROR, "get semaphore failed");
        MD_LOG_EXIT();
        return retVal;
    }

    if( static_cast<CMetricsDevice*>(metricsDevice) != g_MetricsDevice )
    {
        MD_LOG(LOG_ERROR, "pointers mismatch");
        retVal = CC_ERROR_GENERAL;
    }

    if( retVal == CC_OK )
    {
        if( g_mdRefCounter > 1 )
        {
            g_mdRefCounter--;
            retVal = CC_STILL_INITIALIZED;
        }
        else if( g_mdRefCounter == 1 )
        {
            MD_SAFE_DELETE(g_MetricsDevice);
            g_mdRefCounter = 0;
            retVal         = CC_OK;
        }
        else
        {
            retVal = CC_ERROR_GENERAL;
        }
    }

    // disable instrumentation support if needed
    if( pDriverInterface->GetNeedSupportEnable() )
    {
        MD_LOG(LOG_INFO, "driver support disabling...");
        pDriverInterface->SendSupportEnableEscape(false);
    }

    ReleaseOpenCloseSemaphore( &g_OpenCloseSemaphore );
    if( !g_mdRefCounter )
    {
        DestroyDriverIfc();
    }

    MD_LOG_EXIT();
    return retVal;
}

TCompletionCode OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_5** device )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( device, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode retVal = CC_OK;

    // Init driver interface if needed
    CDriverInterface *pDriverInterface = GetDriverIfc();
    if( !pDriverInterface )
    {
        MD_LOG(LOG_ERROR, "failed to get driver interface");
        MD_LOG_EXIT();
        return CC_ERROR_NOT_SUPPORTED;
    }

    if( pDriverInterface->GetNeedSupportEnable() )
    {
        MD_LOG(LOG_DEBUG, "enabling driver support");
        retVal = pDriverInterface->SendSupportEnableEscape(true);
        if( retVal != CC_OK )
        {
            MD_LOG(LOG_ERROR, "driver support enabling failed");
            MD_LOG_EXIT();
            return retVal;
        }
    }

    retVal = GetOpenCloseSemaphore( &g_OpenCloseSemaphore );
    if( retVal != CC_OK )
    {
        MD_LOG(LOG_ERROR, "get semaphore failed");
        MD_LOG_EXIT();
        return retVal;
    }

    if( g_MetricsDevice == NULL )
    {
        g_MetricsDevice = new (std::nothrow) CMetricsDevice();
        if( g_MetricsDevice == NULL )
        {
            retVal = CC_ERROR_NO_MEMORY;
        }
        else
        {
            retVal = CreateMetricTree( g_MetricsDevice );
        }
    }

    if( retVal == CC_OK )
    {
        if( g_MetricsDevice->IsOpenedFromFile() )
        {
            retVal  = CC_ALREADY_INITIALIZED;
            *device = g_MetricsDevice;
            g_mdRefCounter++;
        }
        else
        {
            retVal = CreateObjectTreeFromFile( fileName, device );
            if( retVal == CC_OK )
            {
                g_mdRefCounter++;
            }
        }
    }

    ReleaseOpenCloseSemaphore( &g_OpenCloseSemaphore );
    MD_LOG_EXIT();
    return retVal;
}

TCompletionCode SaveMetricsDeviceToFile(const char* fileName, void* saveParams, IMetricsDevice_1_5* device)
{
    MD_LOG_ENTER();
    TCompletionCode retVal = CC_OK;
    retVal = SaveObjectTreeToFile(fileName, device);

    MD_LOG_EXIT();
    return retVal;
}

#ifdef __cplusplus
    }
#endif