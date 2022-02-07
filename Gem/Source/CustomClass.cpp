#include <BehaviorIssue/CustomClass.h>

#include <AzCore/RTTI/BehaviorContext.h>
#include <AzCore/Serialization/SerializeContext.h>

namespace Ridiculous
{
	void CustomType::Reflect(AZ::ReflectContext* context)
	{

		if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
		{
			// Suggested by an asset processor error, yet it isn't necessary for AZStd::vector.
			serializeContext->Class<AZStd::map<int, CustomType, AZStd::less<int>, AZStd::allocator>>();

			serializeContext->Class<CustomType>()->Version(1)->Field(
				"TheAnswerToLifeTheUniverseAndEverything", &CustomType::TheAnswerToLifeTheUniverseAndEverything);
		}

		if (auto behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
		{
			// The line below is suggested by the asset processor, but isn't necessary for AZStd::vector
			// for whatever reason.
			// 
			// Adding it, along with the corresponding version in AZ::SerializeContext, gets rid of the
			// error pop up, but doesn't fully solve the problem. The map will show up when extracting
			// the properties of CustomType in SC (Script Canvas), but you can't create a variable of it, 
			// nor can you use most of the container functions with it. THe only one that works is For Each.
			//
			// If this line and the corresponding one reflected to the serailize context are commented out,
			// then an invalid type is shown when extracting properties in SC - except for AZStd::vector
			// which doesn't seem to need it.
			// 
			// It also seems to create a duplicate Map variable type inside the Variable Manager in SC.
			//
			behaviorContext->Class<AZStd::map<int, CustomType, AZStd::less<int>, AZStd::allocator>>();

			behaviorContext->Class<CustomType>("CustomType")
				->Attribute(AZ::Script::Attributes::Scope, AZ::Script::Attributes::ScopeFlags::Common)
				->Attribute(AZ::Script::Attributes::Module, "surewhynot")
				->Constructor()
				->Constructor<const CustomType&>()
				->Property(
					"TheAnswerToLifeTheUniverseAndEverything", BehaviorValueProperty(&CustomType::TheAnswerToLifeTheUniverseAndEverything));
		}
	}

	void SomeOtherTypeThatHasAMemberToCustomType::Reflect(AZ::ReflectContext* context)
	{
		CustomType::Reflect(context);

		if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
		{
			serializeContext->Class<SomeOtherTypeThatHasAMemberToCustomType>()
				->Version(42)
				->Field(
					"AVectorContainingCustomTypes", &SomeOtherTypeThatHasAMemberToCustomType::m_aVectorContainingCustomTypes) // Works in SC
				->Field(
					"AMapContainingCustomTypes", &SomeOtherTypeThatHasAMemberToCustomType::m_aMapContainingCustomTypes); // Does not work in SC
		}

		if (auto behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
		{
			behaviorContext->Class<SomeOtherTypeThatHasAMemberToCustomType>("SomeOtherTypeThatHasAMemberToCustomType")
				->Attribute(AZ::Script::Attributes::Scope, AZ::Script::Attributes::ScopeFlags::Common)
				->Attribute(AZ::Script::Attributes::Module, "surewhynot")
				->Constructor()
				->Constructor<const SomeOtherTypeThatHasAMemberToCustomType&>()
				->Property(
					"AVectorContainingCustomTypes",
					BehaviorValueProperty(&SomeOtherTypeThatHasAMemberToCustomType::m_aVectorContainingCustomTypes)) // Works in SC
				->Property(
					"AMapContainingCustomTypes",
					BehaviorValueProperty(&SomeOtherTypeThatHasAMemberToCustomType::m_aMapContainingCustomTypes)); // Does not work in SC
		}
	}
} // namespace Ridiculous
