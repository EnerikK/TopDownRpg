// Hello

#pragma once

#include "CoreMinimal.h"
#include "AuraGameplayTags.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "GameplayTagContainer.h"
#include "SpellMenuWidgetController.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSpellGlobeSelectedSignature,bool,bSpendPointsButtonEnabled,bool,bEquippedButtonEnabled,FString,DescriptionString,FString,NextLevelDescriptionString);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaitForEquipSelectionSiganture,const FGameplayTag& ,AbilityType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpellGlobeReassignedSignature,const FGameplayTag& ,AbilityType);



struct FSelectedAbility
{
	FGameplayTag Ability = FGameplayTag();
	FGameplayTag Status = FGameplayTag();
	
};
/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class AURA_API USpellMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:

	virtual void BroadcastInitialValues() override;
	virtual void BindCallBacksToDependencies() override;


	UPROPERTY(BlueprintAssignable)
	FOnPlayerStatChangedSignature SpellPointsChanged;

	UPROPERTY(BlueprintAssignable)
	FSpellGlobeSelectedSignature SpellGlobeSelectedDelegate;

	UPROPERTY(BlueprintAssignable)
	FWaitForEquipSelectionSiganture WaitForEquipDelegate;
	
	UPROPERTY(BlueprintAssignable)
	FWaitForEquipSelectionSiganture StopWaitingForEquipDelegate;

	UPROPERTY(BlueprintAssignable)
	FSpellGlobeReassignedSignature SpellGlobeReassignedDelegate;
	
	UFUNCTION(BlueprintCallable)
	void SpellGlobeSelected(const FGameplayTag& AbilityTag);

	UFUNCTION(BlueprintCallable)
	void SpendPointButtonPressed();

	UFUNCTION(BlueprintCallable)
	void DeSelectAbility();

	UFUNCTION(BlueprintCallable)
	void EquipButtonPressed();
	
	UFUNCTION(BlueprintCallable)
	void SpellRowPressed(const FGameplayTag& SlotTag,const FGameplayTag& AbilityType);

	void OnAbilityEquipped(const FGameplayTag& AbilityTag , const FGameplayTag& Status , const FGameplayTag& Slot , const FGameplayTag& PreviousSlot);


private:

	static void ShouldEnableButtons(const FGameplayTag& AbilityStatus,int32 SpellPoints, bool& bShouldEnableSpellPointsButton,bool& bShouldEnableEquipButton);
	FSelectedAbility SelectedAbility = {FAuraGameplayTags::Get().Abilities_None , FAuraGameplayTags::Get().Abilities_Status_Locked};
	int32 CurrentSpellPoints = 0;
	bool bWaitingForEquipSelection = false;

	FGameplayTag SelectedSlot;


	
};
