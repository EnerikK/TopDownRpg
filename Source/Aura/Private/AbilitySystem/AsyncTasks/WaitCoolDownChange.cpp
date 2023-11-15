// Hello


#include "AbilitySystem/AsyncTasks/WaitCoolDownChange.h"
#include "AbilitySystemComponent.h"

UWaitCoolDownChange* UWaitCoolDownChange::WaitForCooldownChange(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayTag& InCooldownTag)
{
	UWaitCoolDownChange* WaitCoolDownChange = NewObject<UWaitCoolDownChange>();
	WaitCoolDownChange->ASC = AbilitySystemComponent;
	WaitCoolDownChange->CooldownTag = InCooldownTag;

	if(!IsValid(AbilitySystemComponent) || !InCooldownTag.IsValid())
	{
		WaitCoolDownChange->EndTask();
		return nullptr;
	}
	//To know when a cooldown has ended (cooldownTag has been removed)
	AbilitySystemComponent->RegisterGameplayTagEvent(
		InCooldownTag,
		EGameplayTagEventType::NewOrRemoved).AddUObject
	    (WaitCoolDownChange
		,&UWaitCoolDownChange::CooldownTagChanged);

	//To know when a cooldown effect has been applied 
	AbilitySystemComponent->OnActiveGameplayEffectAddedDelegateToSelf.AddUObject(WaitCoolDownChange,&UWaitCoolDownChange::OnActiveEffectAdded);
	return WaitCoolDownChange;


	
}

void UWaitCoolDownChange::EndTask()
{
	if(!IsValid(ASC)) return;
	ASC->RegisterGameplayTagEvent(CooldownTag,EGameplayTagEventType::NewOrRemoved).RemoveAll(this);
	SetReadyToDestroy();
	MarkAsGarbage();


	
}

void UWaitCoolDownChange::CooldownTagChanged(const FGameplayTag InCooldownTag, int32 NewCount)
{
	if(NewCount == 0)
	{
		CooldownEnd.Broadcast(0.f);
	}
	
}

void UWaitCoolDownChange::OnActiveEffectAdded(UAbilitySystemComponent* TargetASC,
	const FGameplayEffectSpec& SpecApplied, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer AssetTags;
	SpecApplied.GetAllAssetTags(AssetTags);
	
	FGameplayTagContainer GrantedTags;
	SpecApplied.GetAllGrantedTags(GrantedTags);

	if(AssetTags.HasTagExact(CooldownTag) || GrantedTags.HasTagExact(CooldownTag))
	{
		FGameplayEffectQuery GameplayEffectQuery =  FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(CooldownTag.GetSingleTagContainer());
		TArray<float> TimesRemaining  = ASC->GetActiveEffectsTimeRemaining(GameplayEffectQuery);
		if(TimesRemaining.Num() > 0 )
		{
			
			float TimeRemaining = TimesRemaining[0];
			for(int32 i = 0; i < TimesRemaining.Num(); i++)
			{
				if(TimesRemaining[i] > TimeRemaining)
				{
					TimeRemaining = TimesRemaining[i];
				}
			}
			 CooldownStart.Broadcast(TimeRemaining);
		}
	}

}
