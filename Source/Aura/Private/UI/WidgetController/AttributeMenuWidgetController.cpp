// Hello


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Player/AuraPlayerState.h"

void UAttributeMenuWidgetController::BindCallBacksToDependencies()
{
	
	check(AttributeInfo);
	for (auto Pair : GetAuraAS()->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
	[this,Pair](const FOnAttributeChangeData& Data)
		{
			BroadCastAttributeInfo(Pair.Key,Pair.Value());
		}
		);
	}
	
	GetAuraPS()->OnAttributePointsChangedDelegate.AddLambda(
	[this](int32 Points)
	{
		AttributePointsChangedDelegate.Broadcast(Points);
	});
	
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo);
	for(auto& Pair: AS->TagsToAttributes)
	{
		BroadCastAttributeInfo(Pair.Key,Pair.Value());
	}

	
	AttributePointsChangedDelegate.Broadcast(GetAuraPS()->GetAttributePoints());
	
	
}

void UAttributeMenuWidgetController::UpgradeAttribute(const FGameplayTag& AttributeTag)
{
	UAuraAbilitySystemComponent* AuraASC = CastChecked<UAuraAbilitySystemComponent>(AbilitySystemComponent);
	AuraASC->UpgradeAttribute(AttributeTag);
}

void UAttributeMenuWidgetController::BroadCastAttributeInfo(const FGameplayTag& AttributeTag,
                                                            const FGameplayAttribute& Attribute) const 
{
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
