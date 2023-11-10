// Hello


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	//Primary
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Strength"),
		FString("Increases Damage"));

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Intelligence"),
		FString("Increases magic damage"));

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Resilience"),
	FString("Increases Armor and Armor Penetration"));

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Vigor"),
	FString("Increases Health"));


	
	//Secondary  
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.Armor"),
		FString("Reduces Damage taken"));

	GameplayTags.Attributes_Secondary_ArmorPenetration= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.ArmorPenetration"),
		FString("Ignores Percentage of enemy armor"));

	GameplayTags.Attributes_Secondary_BlockChance= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.BlockChance"),
		FString("Chance to block damage"));

	GameplayTags.Attributes_Secondary_CriticalHitChance= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.CriticalHitChance"),
		FString("Chance to do crit damage"));

	GameplayTags.Attributes_Secondary_CriticalHitDamage= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.CriticalHitDamage"),
		FString("Higher crit damage"));

	GameplayTags.Attributes_Secondary_CriticalHitResistance= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.CriticalHitResistance"),
		FString("Reduces crit hit chance when attacking "));

	GameplayTags.Attributes_Secondary_HealthRegeneration= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.HealthRegeneration"),
		FString("Higher HP/s"));

	GameplayTags.Attributes_Secondary_ManaRegeneration= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.ManaRegeneration"),
		FString("Higher MP/s"));

	GameplayTags.Attributes_Secondary_MaxHealth= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.MaxHealth"),
		FString("Increases MaxHealth"));
	
	GameplayTags.Attributes_Secondary_MaxMana= UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Secondary.MaxMana"),
		FString("Increases MaxMana"));

	//Input Tags

	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.LMB"),
		FString("Input tag for left mouse button"));

	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.RMB"),
		FString("Input tag for right mouse button"));

	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.1"),
		FString("Input tag for 1 key"));

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.2"),
		FString("Input tag for 2 key"));

	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.3"),
		FString("Input tag for 3 key"));

	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.4"),
		FString("Input tag for 4 key"));
	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag
			(FName("Damage"),
			FString("Damage"));
	/*
	 * DamageTypes
	 */
	GameplayTags.Damage_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Damage.Fire"),
		FString("Fire Damage"));
	GameplayTags.Damage_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Damage.Lightning"),
		FString("Lightning Damage"));
	GameplayTags.Damage_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Damage.Arcane"),
		FString("Arcane Damage"));
	GameplayTags.Damage_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Damage.Physical"),
		FString("Physical Damage"));

	/*
	 * Resistances
	 */
	GameplayTags.Attributes_Resistance_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Resistance.Arcane"),
		FString("Resistance to Arcane type Damage"));
	
	GameplayTags.Attributes_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Resistance.Fire"),
		FString("Resistance to Fire type Damage"));
	
	GameplayTags.Attributes_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Resistance.Lightning"),
	FString("Resistance to Lightning type Damage"));
	
	GameplayTags.Attributes_Resistance_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Resistance.Physical"),
		FString("Resistance to Physical type Damage"));
	
	/*
	 * Map of damage type to resistances
	 */
	GameplayTags.DamageTypesResistances.Add(GameplayTags.Damage_Arcane,GameplayTags.Attributes_Resistance_Arcane);
	GameplayTags.DamageTypesResistances.Add(GameplayTags.Damage_Lightning,GameplayTags.Attributes_Resistance_Lightning);
	GameplayTags.DamageTypesResistances.Add(GameplayTags.Damage_Physical,GameplayTags.Attributes_Resistance_Physical);
	GameplayTags.DamageTypesResistances.Add(GameplayTags.Damage_Fire,GameplayTags.Attributes_Resistance_Fire);
	
	/*
	 * Effects
	 */
	//React
	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Effects.HitReact"),
	FString("Tag given when hit reacting"));

	/*
	 * Abilities
	 */
	GameplayTags.Abilities_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Attack"),
	FString("Attack Ability Tag"));

	/*
	* Montage
	*/
	GameplayTags.Montage_Attack_Weapon = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Montage.Attack.Weapon"),
	FString("WeaponAttacks"));
	
	GameplayTags.Montage_Attack_RightHand = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Montage.Attack.RightHand"),
	FString("RightHands Attacks"));
	
	GameplayTags.Montage_Attack_LeftHand = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Montage.Attack.LeftHand"),
	FString("LeftHand Attacks"));


}
