// Hello


#include "AbilitySystem/Data/LvlUpInfo.h"

int32 ULvlUpInfo::FindLevelForXp(int32 XP)const
{
	int32 Level = 1;
	bool bSearching = true;
	while (bSearching)
	{
		//Levelupinformation[1] = level 1 information
		//Levelupinformation[2] = level 1 information
		if(LevelUpInformation.Num() -1  <= Level) return Level;
		if(XP >= LevelUpInformation[Level].LevelUpRequirement)
		{
			++Level;
		}
		else
		{
			bSearching = false;
		}
	}
	return Level;
}
