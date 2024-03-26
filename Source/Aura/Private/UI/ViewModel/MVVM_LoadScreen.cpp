// Hello


#include "UI/ViewModel/MVVM_LoadScreen.h"

#include "Game/AuraGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "UI/ViewModel/MVVM_LoadSlot.h"

void UMVVM_LoadScreen::InitializeLoadSlots()
{
	LoadSlot_0 = NewObject<UMVVM_LoadSlot>(this,LoadSlotViewModelClass);
	LoadSlot_0->LoadSlotName = FString("LoadSlot_0");
	LoadSlot_0->SlotIndex = 0;
	LoadSlot.Add(0,LoadSlot_0);
	
	LoadSlot_1 = NewObject<UMVVM_LoadSlot>(this,LoadSlotViewModelClass);
	LoadSlot_1->LoadSlotName = FString("LoadSlot_1");
	LoadSlot_1->SlotIndex = 1;
	LoadSlot.Add(1,LoadSlot_0);
	
	LoadSlot_2 = NewObject<UMVVM_LoadSlot>(this,LoadSlotViewModelClass);
	LoadSlot_2->LoadSlotName = FString("LoadSlot_2");
	LoadSlot_2->SlotIndex = 2;
	LoadSlot.Add(2,LoadSlot_0);


}

UMVVM_LoadSlot* UMVVM_LoadScreen::GetLoadSlotViewModelByIndex(int32 Index)
{
	return LoadSlot.FindChecked(Index);
	
}
void UMVVM_LoadScreen::NewSlotButtonPressed(int32 Slot, const FString EnteredName)
{
	AAuraGameModeBase* AuraGameMode = Cast<AAuraGameModeBase>(UGameplayStatics::GetGameMode(this));

	LoadSlot[Slot]->SetMapName(AuraGameMode->DefaultMapName);
	
	LoadSlot[Slot]->SetPlayerName(EnteredName);
	LoadSlot[Slot]->SlotStatus = Taken;

	
	AuraGameMode->SaveSlotData(LoadSlot[Slot],Slot);
	LoadSlot[Slot]->InitializeSlot();
	
}
void UMVVM_LoadScreen::NewGameButtonPressed(int32 Slot)
{
	LoadSlot[Slot]->SetWidgetSwitcherIndex.Broadcast(1);
}
void UMVVM_LoadScreen::SelectSlotButtonPressed(int32 Slot)
{
	SlotSelected.Broadcast();
	for (const TTuple<int32,UMVVM_LoadSlot*> Slots : LoadSlot)
	{
		if(Slots.Key == Slot)
		{
			Slots.Value->EnableSelectSlotButton.Broadcast(false);
		}
		else
		{
			Slots.Value->EnableSelectSlotButton.Broadcast(true);
		}
	}
	SelectedSlot = LoadSlot[Slot];
}
void UMVVM_LoadScreen::DeleteButtonPressed(int32 Slot)
{
	if(IsValid(SelectedSlot))
	{
		AAuraGameModeBase::DeleteSlot(SelectedSlot->LoadSlotName,SelectedSlot->SlotIndex);
		SelectedSlot->SlotStatus = Vacant;
		SelectedSlot->InitializeSlot();
		SelectedSlot->EnableSelectSlotButton.Broadcast(true);
	}
}

void UMVVM_LoadScreen::PlayButtonPressed()
{
	AAuraGameModeBase* AuraGameMode = Cast<AAuraGameModeBase>(UGameplayStatics::GetGameMode(this));
	if(IsValid(SelectedSlot))
	{
		AuraGameMode->TravelToMap(SelectedSlot);
	}
	
}

void UMVVM_LoadScreen::LoadData()
{
	AAuraGameModeBase* AuraGameMode = Cast<AAuraGameModeBase>(UGameplayStatics::GetGameMode(this));
	for (const TTuple<int32,UMVVM_LoadSlot*> Slot : LoadSlot)
	{
		ULoadScreenSaveGame* SaveObject = AuraGameMode->GetSaveSlotData(Slot.Value->LoadSlotName,Slot.Key);

		const FString PlayerName = SaveObject->PlayerName;
		TEnumAsByte<ESaveSlotStatus> SaveSlotStatus = SaveObject->SaveSlotStatus;

		Slot.Value->SlotStatus = SaveSlotStatus;
		Slot.Value->SetPlayerName(PlayerName);
		Slot.Value->InitializeSlot();
		Slot.Value->SetMapName(SaveObject->MapName);
	}
}
