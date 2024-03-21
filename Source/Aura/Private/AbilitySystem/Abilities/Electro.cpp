// Hello


#include "AbilitySystem/Abilities/Electro.h"

FString UElectro::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost());
	const float CoolDown = GetCooldown();
	if(Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>Electro</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			"<Default>Shoots a beam of Lightning, "
			"Causing : </>"
			//Damage
			"<Damage>%d</> <Default>Lightning Damage </> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			ScaledDamage);
		
	}
	else
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>Electro</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//Number of hit targets
			"<Default>Shoots a beam of lightning, "
			"up to %d additional targets nearby , causing : </>"
			//Damage
			"<Damage>%d</> <Default>Lighting damage</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			FMath::Min(Level,MaxNumElectroTargets - 1),
			ScaledDamage);
	}
	
}
FString UElectro::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost());
	const float CoolDown = GetCooldown();
	return FString::Printf(TEXT(
			//Title
			"<Title>Next Level</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//Number of hit targets
			"<Default>Shoots a beam of lightning, "
			"up to %d additional targets nearby , causing : </>"
			//Damage
			"<Damage>%d</> <Default>Lighting damage</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			FMath::Min(Level,MaxNumElectroTargets - 1),
			ScaledDamage);
	
}
