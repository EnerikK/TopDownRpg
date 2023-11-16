// Hello


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AbilityInfo.h"
#include "AbilitySystem/Data/LvlUpInfo.h"
#include "Player/AuraPlayerState.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributesSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(AuraAttributesSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributesSet->GetMaxHealth());
	OnManaChanged.Broadcast(AuraAttributesSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributesSet->GetMaxMana());
	
	
}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	AAuraPlayerState* AuraPlayerState = CastChecked<AAuraPlayerState>(PlayerState);
	AuraPlayerState->OnXPChangedDelegate.AddUObject(this,&UOverlayWidgetController::OnXPChanged);
	
	const UAuraAttributeSet* AuraAttributesSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(AuraAttributesSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);

		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(AuraAttributesSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);

		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
	(AuraAttributesSet->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);

		});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate
		(AuraAttributesSet->GetMaxManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);

			});

	if(UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent))
	{
		if(AuraASC->bStartUpAbilitiesGiven)
		{
			OnInitializedStartUpAbilities(AuraASC);
		}
		else
		{
			AuraASC->AbilitiesGivenDelegate.AddUObject(this,&UOverlayWidgetController::OnInitializedStartUpAbilities);
		}
		

		AuraASC->EffectAssetTags.AddLambda(
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

void UOverlayWidgetController::OnInitializedStartUpAbilities(UAuraAbilitySystemComponent* AuraAbilitySystemComponent)
{
	//TODO : GetInformation About all given abilities look up there ability info and broadcast it to widgets.
	if(!AuraAbilitySystemComponent->bStartUpAbilitiesGiven) return;

	FForEachAbility BroadcastDelegate;
	BroadcastDelegate.BindLambda([this, AuraAbilitySystemComponent](const FGameplayAbilitySpec& AbilitySpec)
	{
		//TODO need a way to figure out the ability tag for a given ability spec.
		FAuraAbilityInfo Info = AbilityInfo->FindAbilityInfoForTag(AuraAbilitySystemComponent->GetAbilityTagFromSpec(AbilitySpec));
		Info.InputTag = AuraAbilitySystemComponent->GetInputTagFromSpec(AbilitySpec);
		AbilityInfoDelegate.Broadcast(Info);
	});
	AuraAbilitySystemComponent->ForEachAbility(BroadcastDelegate);
	
}

void UOverlayWidgetController::OnXPChanged(int32 NewXP)const
{
	const AAuraPlayerState* AuraPlayerState = CastChecked<AAuraPlayerState>(PlayerState);
	const ULvlUpInfo* LevelUpInfo = AuraPlayerState->LevelUpInfo;
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
