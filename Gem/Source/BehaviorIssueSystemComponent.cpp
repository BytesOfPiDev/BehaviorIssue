
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "BehaviorIssueSystemComponent.h"

#include <BehaviorIssue/CustomClass.h>

namespace BehaviorIssue
{
    void BehaviorIssueSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        Ridiculous::SomeOtherTypeThatHasAMemberToCustomType::Reflect(context);

        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<BehaviorIssueSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<BehaviorIssueSystemComponent>("BehaviorIssue", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void BehaviorIssueSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("BehaviorIssueService"));
    }

    void BehaviorIssueSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("BehaviorIssueService"));
    }

    void BehaviorIssueSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void BehaviorIssueSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    BehaviorIssueSystemComponent::BehaviorIssueSystemComponent()
    {
        if (BehaviorIssueInterface::Get() == nullptr)
        {
            BehaviorIssueInterface::Register(this);
        }
    }

    BehaviorIssueSystemComponent::~BehaviorIssueSystemComponent()
    {
        if (BehaviorIssueInterface::Get() == this)
        {
            BehaviorIssueInterface::Unregister(this);
        }
    }

    void BehaviorIssueSystemComponent::Init()
    {
    }

    void BehaviorIssueSystemComponent::Activate()
    {
        BehaviorIssueRequestBus::Handler::BusConnect();
    }

    void BehaviorIssueSystemComponent::Deactivate()
    {
        BehaviorIssueRequestBus::Handler::BusDisconnect();
    }
}
