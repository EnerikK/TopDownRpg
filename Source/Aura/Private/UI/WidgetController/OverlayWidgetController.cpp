// Hello


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AbilityInfo.h"
#include "AbilitySystem/Data/LvlUpInfo.h"
#include "Player/AuraPlayerState.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributesSet = GetAuraAS();
	
	OnHealthChanged.Broadcast(GetAuraAS()->GetHealth());
	OnMaxHealthChanged.Broadcast(GetAuraAS()->GetMaxHealth());
	OnManaChanged.Broadcast(GetAuraAS()->GetMana());
	OnMaxManaChanged.Broadcast(GetAuraAS()->GetMaxMana());
	
	
}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	
	GetAuraPS()->OnXPChangedDelegate.AddUObject(this,&UOverlayWidgetController::OnXPChanged);
	GetAuraPS()->OnLevelChangedDelegate.AddLambda(
[this](int32 NewLevel)
	{
		OnPlayerLevelChangedDelegate.Broadcast(NewLevel);
	});
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(GetAuraAS()->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);

		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(GetAuraAS()->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);

		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(GetAuraAS()->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);

		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
		(GetAuraAS()->GetMaxManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);

			});

	if(GetAuraASC())
	{
		if(GetAuraASC()->bStartUpAbilitiesGiven)
		{
			BroadcastAbilityInfo();
		}
		else
		{
			GetAuraASC()->AbilitiesGivenDelegate.AddUObject(this,&UOverlayWidgetController::BroadcastAbilityInfo);
		}
		

		GetAuraASC()->EffectAssetTags.AddLambda(
			[this](const FGameplayTagContainer& AssetTags)
			{
				for (const FGameplayTag& Tag : AssetTags)
				{
					//For example tag = message.health potion
					//"Message.HealthPotion.MatchesTag("A") will return True , "Message".MatchesTag("Message.HealthPotion") will return false
					FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
					if(Tag.MatchesTag(MessageTag))
					{
						const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable,Tag);
						MessageWidgetRowDelegate.Broadcast(*Row);
					}
				}
			}
		);
	}
}

void UOverlayWidgetController::OnXPChanged(int32 NewXP)
{
	
	const ULvlUpInfo* LevelUpInfo = GetAuraPS()->LevelUpInfo;
	checkf(LevelUpInfo,TEXT("Unable to find level up info pls fill out AuraPlayerstate blueprint"));

	const int32 Level = LevelUpInfo->FindLevelForXp(NewXP);
	const int32 MaxLevel = LevelUpInfo->LevelUpInformation.Num();

	if(Level <= MaxLevel && Level > 0 )
	{
		const int32 LevelUpRequirement = LevelUpInfo->LevelUpInformation[Level].LevelUpRequirement;
		const int32 PreviousLevelUpRequirement = LevelUpInfo->LevelUpInformation[Level - 1 ].LevelUpRequirement;

		const int32 DeltaLevelRequirement = LevelUpRequirement - PreviousLevelUpRequirement;
		const int32 XPForThisLevel = NewXP - PreviousLevelUpRequirement;

		const float XPBarPercent  = static_cast<float>(XPForThisLevel) / static_cast<float>(DeltaLevelRequirement);

		OnXPPercentChangedDelegate.Broadcast(XPBarPercent);
	}
	
	
	
}
