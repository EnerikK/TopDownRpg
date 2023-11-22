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
	
	GameplayTags.InputTag_Passive_1 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.Passive.1"),
		FString("Input tag for passive 1"));

	GameplayTags.InputTag_Passive_2 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.Passive.2"),
		FString("Input tag for passive 2"));
	/*
	 * DamageTypes
	 */

	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Damage"),
		FString("Damage"));
	
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
	 * MetaAttributes
	 */
	GameplayTags.Attributes_Meta_IncomingXP = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Attributes.Meta.IncomingXP"),
		FString("Incoming xp meta attribute"));
	
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

	GameplayTags.Abilities_Summon = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Summon"),
	FString("Summon Ability Tag"));
	
	GameplayTags.Abilities_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Fire.FireBolt"),
	FString("FireBolt Ability Tag"));
	
	GameplayTags.Abilities_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.HitReact"),
	FString("Hit react abilities"));

	GameplayTags.Abilities_Status_Eligible = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Status.Eligible"),
	FString("Eligible status"));

	GameplayTags.Abilities_Status_Equipped = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Status.Equipped"),
	FString("Equipped status"));

	GameplayTags.Abilities_Status_Locked = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Status.Locked"),
	FString("Locked status"));

	GameplayTags.Abilities_Status_Unlocked = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Status.Unlocked"),
	FString("Unlocked status"));

	GameplayTags.Abilities_Type_None = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Type.None"),
	FString("Type None"));

	GameplayTags.Abilities_Type_Offensive = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Type.Offensive"),
	FString("Type Offensive"));
	
	GameplayTags.Abilities_Type_Passive = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Abilities.Type.Passive"),
	FString("Type Passive"));


	

	/*
	 * Ability Cooldown
	 */
	GameplayTags.Cooldown_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Cooldown.Fire.FireBolt"),
	FString("FireBolt Cooldown Tag"));

	/*
	* Combat sockets
	*/
	GameplayTags.CombatSocket_Weapon = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("CombatSocket.Weapon"),
	FString("WeaponAttacks"));
	
	GameplayTags.CombatSocket_RightHand = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("CombatSocket.RightHand"),
	FString("RightHands Attacks"));
	
	GameplayTags.CombatSocket_LeftHand = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("CombatSocket.LeftHand"),
	FString("LeftHand Attacks"));

	GameplayTags.CombatSocket_Tail = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("CombatSocket.Tail"),
	FString("Tail Attacks"));


	/*
	* MontageTags
	*/
	GameplayTags.Montage_Attack_1 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Montage.Attack.1"),
	FString("Attack 1"));
	GameplayTags.Montage_Attack_2 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Montage.Attack.2"),
	FString("Attack 2"));
	GameplayTags.Montage_Attack_3 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Montage.Attack.3"),
	FString("Attack 3"));
	GameplayTags.Montage_Attack_4 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Montage.Attack.4"),
	FString("Attack 4"));


}
