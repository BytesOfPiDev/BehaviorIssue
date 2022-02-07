
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace BehaviorIssue
{
    class BehaviorIssueRequests
    {
    public:
        AZ_RTTI(BehaviorIssueRequests, "{6b5ceb7c-e77b-48b1-988d-f074ae8457e3}");
        virtual ~BehaviorIssueRequests() = default;
        // Put your public methods here
    };

    class BehaviorIssueBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using BehaviorIssueRequestBus = AZ::EBus<BehaviorIssueRequests, BehaviorIssueBusTraits>;
    using BehaviorIssueInterface = AZ::Interface<BehaviorIssueRequests>;

} // namespace BehaviorIssue
