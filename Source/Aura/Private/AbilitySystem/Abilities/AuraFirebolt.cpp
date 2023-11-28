// Hello


#include "AbilitySystem/Abilities/AuraFirebolt.h"
#include "AuraGameplayTags.h"


FString UAuraFirebolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost());
	const float CoolDown = GetCooldown();
	if(Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>Fire Bolt</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			"<Default>Launches a bolt of fire, "
			"exploding on impact and dealing : </>"
			//Damage
			"<Damage>%d</> <Default>Damage</> \n\n"
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
			"<Title>Fire Bolt</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//Number of fire bolts
			"<Default>Launches %d bolts of fire, "
			"exploding on impact and dealing : </>"
			//Damage
			"<Damage>%d</> <Default>Damage</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			FMath::Min(Level,NumProjectiles),
			ScaledDamage);
	}
	
}

FString UAuraFirebolt::GetNextLevelDescription(int32 Level)
{
	const float ManaCost = FMath::Abs(GetManaCost());
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
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
			//Number of fire bolts
			"<Default>Launches %d bolts of fire, "
			"exploding on impact and dealing : </>"
			//Damage
			"<Damage>%d</> <Default>Damage</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			FMath::Min(Level,NumProjectiles),
			ScaledDamage);
}