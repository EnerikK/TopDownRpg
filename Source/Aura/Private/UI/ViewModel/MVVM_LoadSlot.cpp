// Hello


#include "UI/ViewModel/MVVM_LoadSlot.h"

void UMVVM_LoadSlot::InitializeSlot()
{
	//Check slot status based on loaded data
	SetWidgetSwitcherIndex.Broadcast(1);
}
void UMVVM_LoadSlot::SetPlayerName(FString InPlayerName)
{
	UE_MVVM_SET_PROPERTY_VALUE(PlayerName,InPlayerName);	
}
