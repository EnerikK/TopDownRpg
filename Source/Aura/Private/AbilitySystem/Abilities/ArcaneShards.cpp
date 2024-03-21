// Hello


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost());
	const float CoolDown = GetCooldown();
	if(Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>Arcane Shard</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			"<Default>Spawns an Arcane Shard, "
			"Causing radial Arcane  damage of : </>"
			//Damage
			"<Damage>%d</> <Default>at the shard origin </> \n\n"
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
			"<Title>Arcane Shards</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//Number of hit targets
			"<Default>Spawns %d Arcane Shards, "
			",causing : </>"
			//Damage
			"<Damage>%d</> <Default> damage at the shard origin</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			FMath::Min(Level,MaxNumShards + 1),
			ScaledDamage);
	}
}
FString UArcaneShards::GetNextLevelDescription(int32 Level)
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
			"<Default>Spawns %d Arcane Shards, "
			",causing : </>"
			//Damage
			"<Damage>%d</> <Default> damage at the shard origin</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			FMath::Min(Level,MaxNumShards + 1),
			ScaledDamage);
}
