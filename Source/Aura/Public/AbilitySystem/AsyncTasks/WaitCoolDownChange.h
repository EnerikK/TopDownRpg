// Hello

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameplayTagContainer.h"
#include "WaitCoolDownChange.generated.h"

struct FGameplayTag;
class UAbilitySystemComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCoolDownChangeSignature, float, TimeRemaining);
/**
 * 
 */
UCLASS(BlueprintType,meta=(ExposedAsyncProxy = "AsyncTask"))
class AURA_API UWaitCoolDownChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FCoolDownChangeSignature CooldownStart;
	
	UPROPERTY(BlueprintAssignable)
	FCoolDownChangeSignature CooldownEnd;

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = " true "))
	static UWaitCoolDownChange* WaitForCooldownChange(UAbilitySystemComponent* AbilitySystemComponent,const FGameplayTag& InCooldownTag);

	UFUNCTION(BlueprintCallable)
	void EndTask();
protected:

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> ASC;
	
	FGameplayTag CooldownTag;

	void CooldownTagChanged(const FGameplayTag InCooldownTag,int32 NewCount);
	void OnActiveEffectAdded(UAbilitySystemComponent* TargetASC , const FGameplayEffectSpec& SpecApplied , FActiveGameplayEffectHandle ActiveEffectHandle);
	
};

