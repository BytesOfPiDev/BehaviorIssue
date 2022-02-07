
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "BehaviorIssueSystemComponent.h"

namespace BehaviorIssue
{
    class BehaviorIssueModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(BehaviorIssueModule, "{8722c88d-a6fa-4799-bb33-92b3a333a0e5}", AZ::Module);
        AZ_CLASS_ALLOCATOR(BehaviorIssueModule, AZ::SystemAllocator, 0);

        BehaviorIssueModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                BehaviorIssueSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<BehaviorIssueSystemComponent>(),
            };
        }
    };
}// namespace BehaviorIssue

AZ_DECLARE_MODULE_CLASS(Gem_BehaviorIssue, BehaviorIssue::BehaviorIssueModule)
