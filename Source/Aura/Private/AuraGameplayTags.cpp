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

	//Damage
	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("Damage"),
		FString("Damage"));

	//React
	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Effects.HitReact"),
	FString("Tag given when hit reacting"));


}
