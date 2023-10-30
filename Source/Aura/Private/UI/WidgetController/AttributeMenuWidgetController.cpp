// Hello


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AuraGameplayTags.h"

void UAttributeMenuWidgetController::BindCallBacksToDependencies()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
	[this,Pair,AS](const FOnAttributeChangeData& Data)
		{
			BroadCastAttributeInfo(Pair.Key,Pair.Value());
		}
		);
	}
	
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo);
	for(auto& Pair: AS->TagsToAttributes)
	{
		BroadCastAttributeInfo(Pair.Key,Pair.Value());
	}
	
	
}

void UAttributeMenuWidgetController::BroadCastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const 
{
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
