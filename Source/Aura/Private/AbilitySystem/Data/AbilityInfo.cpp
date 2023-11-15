// Hello


#include "AbilitySystem/Data/AbilityInfo.h"
#include "Aura/AuraLogChannels.h"

FAuraAbilityInfo UAbilityInfo::FindAbilityInfoForTag(const FGameplayTag& AbilityTag, bool bNotFound) const
{
	for (const FAuraAbilityInfo& Info : AbilityInformation)
	{
		if(Info.AbilityTag == AbilityTag)
		{
			return Info;
		}
	}
	if(bNotFound)
	{
		UE_LOG(LogAura,Error,TEXT("Cant find info for ability tag [%s] on ability info [%s]"),*AbilityTag.ToString(),*GetNameSafe(this));
	}
	
	return FAuraAbilityInfo();
}
