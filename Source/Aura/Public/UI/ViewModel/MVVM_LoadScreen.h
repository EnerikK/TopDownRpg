// Hello

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MVVM_LoadScreen.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSlotSelected);


class UMVVM_LoadSlot;
/**
 * 
 */
UCLASS()
class AURA_API UMVVM_LoadScreen : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:

	void InitializeLoadSlots();

	UPROPERTY(BlueprintAssignable)
	FSlotSelected SlotSelected;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMVVM_LoadSlot> LoadSlotViewModelClass;

	UFUNCTION(BlueprintPure)
	UMVVM_LoadSlot* GetLoadSlotViewModelByIndex(int32 Index);

	UFUNCTION(BlueprintCallable)
	void NewSlotButtonPressed(int32 Slot,const FString EnteredName);

	UFUNCTION(BlueprintCallable)
	void NewGameButtonPressed(int32 Slot);

	UFUNCTION(BlueprintCallable)
	void SelectSlotButtonPressed(int32 Slot);
	
	UFUNCTION(BlueprintCallable)
	void DeleteButtonPressed(int32 Slot);

	UFUNCTION(BlueprintCallable)
	void PlayButtonPressed();

	void LoadData();
	
private:

	UPROPERTY()
	TMap<int32,UMVVM_LoadSlot*> LoadSlot;

	TObjectPtr<UMVVM_LoadSlot> LoadSlot_0;

	TObjectPtr<UMVVM_LoadSlot> LoadSlot_1;
	
	TObjectPtr<UMVVM_LoadSlot> LoadSlot_2;
	
	UPROPERTY()
	UMVVM_LoadSlot* SelectedSlot;
};
