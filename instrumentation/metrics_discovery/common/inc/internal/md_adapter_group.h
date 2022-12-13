/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_adapter_group.h

//     Abstract:   C++ Metrics Discovery internal adapter group header

#pragma once

#include "metrics_discovery_internal_api.h"

#include <vector>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    struct SAdapterData;
    using TAdapterData = SAdapterData;

    class CAdapter;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Description:
    //     GPU adapters root object. Stores all currently available and supported Intel adapters.
    //     One instance for the whole library.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CAdapterGroup : public IAdapterGroupLatest
    {
    public:
        virtual IAdapterLatest*                  GetAdapter( uint32_t index );
        virtual const TAdapterGroupParamsLatest* GetParams() const;
        virtual TCompletionCode                  Close();

    public:
        // Non-API:
        CAdapter* GetDefaultAdapter();

        // Non-API static:
        static TCompletionCode Open( CAdapterGroup** adapterGroup );
        static bool            IsOpened();
        static CAdapterGroup*  Get();

    protected:
        // Constructor & Destructor:
        CAdapterGroup();
        virtual ~CAdapterGroup();

    private:
        CAdapterGroup( const CAdapterGroup& )            = delete; // Delete copy-constructor
        CAdapterGroup& operator=( const CAdapterGroup& ) = delete; // Delete assignment operator

        // Adapter handling:
        TCompletionCode CreateAdapterTree();
        TCompletionCode AddAdapter( const TAdapterData& adapterData );
        void            CleanupAdapters();
        CAdapter*       ChooseDefaultAdapter();

        // Static:
        static TCompletionCode GetOpenCloseSemaphore();
        static TCompletionCode ReleaseOpenCloseSemaphore();
        static TCompletionCode CreateAdapterGroup( CAdapterGroup** adapterGroup );

    private:
        // Variables:
        TAdapterGroupParamsLatest m_params;
        CAdapter*                 m_defaultAdapter;
        std::vector<CAdapter*>    m_adapterVector;

    private:
        // Static Variables:
        inline static void*          m_openCloseSemaphore = nullptr;
        inline static uint32_t       m_agRefCounter       = 0;
        inline static CAdapterGroup* m_adapterGroup       = nullptr;

        static constexpr uint32_t ADAPTER_VECTOR_INCREASE = 8;
    };
} // namespace MetricsDiscoveryInternal
