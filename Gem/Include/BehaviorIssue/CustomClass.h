#pragma once

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/RTTI/ReflectContext.h>
#include <AzCore/std/containers/vector.h>

namespace Ridiculous
{
    struct CustomType
    {
    public:
        AZ_TYPE_INFO(CustomType, "{469C60F2-42DC-434C-9B69-58880FEC9161}");
        AZ_CLASS_ALLOCATOR(CustomType, AZ::SystemAllocator, 0);

        static void Reflect(AZ::ReflectContext* context);

        CustomType() = default;
        CustomType(const CustomType&) = default;
        ~CustomType() = default;

        int TheAnswerToLifeTheUniverseAndEverything = 42;
    };

    struct SomeOtherTypeThatHasAMemberToCustomType
    {
        AZ_TYPE_INFO(SomeOtherTypeThatHasAMemberToCustomType, "{64DE0FCA-BF92-44D4-BFD9-8B9B4324D65D}");
        AZ_CLASS_ALLOCATOR(SomeOtherTypeThatHasAMemberToCustomType, AZ::SystemAllocator, 0);

        static void Reflect(AZ::ReflectContext* context);

        SomeOtherTypeThatHasAMemberToCustomType() = default;
        SomeOtherTypeThatHasAMemberToCustomType(const SomeOtherTypeThatHasAMemberToCustomType&) = default;
        ~SomeOtherTypeThatHasAMemberToCustomType() = default;

        AZStd::vector<CustomType> m_aVectorContainingCustomTypes; // Works
        AZStd::map<int, CustomType> m_aMapContainingCustomTypes; // Does not work
    };

} // namespace Ridiculous
