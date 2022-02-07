
#pragma once

#include <AzCore/Component/Component.h>

#include <BehaviorIssue/BehaviorIssueBus.h>

namespace BehaviorIssue
{
    class BehaviorIssueSystemComponent
        : public AZ::Component
        , protected BehaviorIssueRequestBus::Handler
    {
    public:
        AZ_COMPONENT(BehaviorIssueSystemComponent, "{cb7e7761-c50c-442f-b668-9fdb45d63e35}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        BehaviorIssueSystemComponent();
        ~BehaviorIssueSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // BehaviorIssueRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
