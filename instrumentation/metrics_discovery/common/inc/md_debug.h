/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_debug.h

//     Abstract:   Header with Metrics Discovery debug functions and macros

#pragma once

#include "iu_debug.h"

/////////////////////////////////////////////////////////////
// METRICS DISCOVERY LAYER LOGS
/////////////////////////////////////////////////////////////
// Tag to prefix log messages with
#if !defined( MDAPI_LOG_TAG )
    #define MDAPI_LOG_TAG "[MDAPI]"
#endif

#define MD_ASSERT( expr )    IU_ASSERT_TAGGED( IU_ADAPTER_ID_UNKNOWN, expr, IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG )
#define MD_LOG( level, ... ) IU_DBG_PRINT_TAGGED( IU_ADAPTER_ID_UNKNOWN, _##level, IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG, __FUNCTION__, __VA_ARGS__ )
#define MD_LOG_ENTER()       IU_DBG_FUNCTION_ENTER_TAGGED( IU_ADAPTER_ID_UNKNOWN, _LOG_DEBUG, IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG );
#define MD_LOG_EXIT()        IU_DBG_FUNCTION_EXIT_TAGGED( IU_ADAPTER_ID_UNKNOWN, _LOG_DEBUG, IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG )

#define MD_LOG_INVALID_PARAMETER( level, variable ) MD_LOG( level, "invalid parameter: %s", #variable );

//////////////////////////////////////////////////////////////////////////////
// MACRO: Following macros are required for compatibility between IU debug framework
//        and current MDAPI logs.
//////////////////////////////////////////////////////////////////////////////
#define _LOG_ERROR   IU_DBG_SEV_ERROR
#define _LOG_WARNING IU_DBG_SEV_WARNING
#define _LOG_INFO    IU_DBG_SEV_INFO
#define _LOG_DEBUG   IU_DBG_SEV_DEBUG

#define __LOG_ERROR   IU_DBG_SEV_ERROR
#define __LOG_WARNING IU_DBG_SEV_WARNING
#define __LOG_INFO    IU_DBG_SEV_INFO
#define __LOG_DEBUG   IU_DBG_SEV_DEBUG

#define F__LOG_ERROR( adapter, level, layer, ... )   F_IU_DBG_SEV_ERROR( adapter, level, layer, __VA_ARGS__ )
#define F__LOG_WARNING( adapter, level, layer, ... ) F_IU_DBG_SEV_WARNING( adapter, level, layer, __VA_ARGS__ )
#define F__LOG_INFO( adapter, level, layer, ... )    F_IU_DBG_SEV_INFO( adapter, level, layer, __VA_ARGS__ )
#define F__LOG_DEBUG( adapter, level, layer, ... )   F_IU_DBG_SEV_DEBUG( adapter, level, layer, __VA_ARGS__ )

#define F___LOG_ERROR( adapter, level, layer, ... )   F_IU_DBG_SEV_ERROR( adapter, level, layer, __VA_ARGS__ )
#define F___LOG_WARNING( adapter, level, layer, ... ) F_IU_DBG_SEV_WARNING( adapter, level, layer, __VA_ARGS__ )
#define F___LOG_INFO( adapter, level, layer, ... )    F_IU_DBG_SEV_INFO( adapter, level, layer, __VA_ARGS__ )
#define F___LOG_DEBUG( adapter, level, layer, ... )   F_IU_DBG_SEV_DEBUG( adapter, level, layer, __VA_ARGS__ )
