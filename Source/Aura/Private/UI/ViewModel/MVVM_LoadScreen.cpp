// Hello


#include "UI/ViewModel/MVVM_LoadScreen.h"

#include "Game/AuraGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "UI/ViewModel/MVVM_LoadSlot.h"

void UMVVM_LoadScreen::InitializeLoadSlots()
{
	LoadSlot_0 = NewObject<UMVVM_LoadSlot>(this,LoadSlotViewModelClass);
	LoadSlot_0->LoadSlotName = FString("LoadSlot_0");
	LoadSlot.Add(0,LoadSlot_0);
	
	LoadSlot_1 = NewObject<UMVVM_LoadSlot>(this,LoadSlotViewModelClass);
	LoadSlot_1->LoadSlotName = FString("LoadSlot_1");
	LoadSlot.Add(1,LoadSlot_0);
	
	LoadSlot_2 = NewObject<UMVVM_LoadSlot>(this,LoadSlotViewModelClass);
	LoadSlot_2->LoadSlotName = FString("LoadSlot_2");
	LoadSlot.Add(2,LoadSlot_0);


}

UMVVM_LoadSlot* UMVVM_LoadScreen::GetLoadSlotViewModelByIndex(int32 Index)
{
	return LoadSlot.FindChecked(Index);
	
}
void UMVVM_LoadScreen::NewSlotButtonPressed(int32 Slot, const FString EnteredName)
{
	AAuraGameModeBase* AuraGameMode = Cast<AAuraGameModeBase>(UGameplayStatics::GetGameMode(this));
	
	LoadSlot[Slot]->SetPlayerName(EnteredName);
	
	AuraGameMode->SaveSlotData(LoadSlot[Slot],Slot);
	LoadSlot[Slot]->InitializeSlot();
	
}
void UMVVM_LoadScreen::NewGameButtonPressed(int32 Slot)
{
	LoadSlot[Slot]->SetWidgetSwitcherIndex.Broadcast(1);
}
void UMVVM_LoadScreen::SelectSlotButtonPressed(int32 Slot)
{
	
}
