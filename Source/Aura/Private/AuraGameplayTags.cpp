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



}
