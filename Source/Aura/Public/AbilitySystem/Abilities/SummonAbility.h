// Hello

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"
#include "SummonAbility.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API USummonAbility : public UAuraGameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	TArray<FVector> GetSpawnLocation();

	UFUNCTION(BlueprintPure,Category="Summoning")
	TSubclassOf<APawn> GetRandomMinionClass();

	UPROPERTY(EditDefaultsOnly,Category="Summoning")
	int32 NumMinions = 2;

	UPROPERTY(EditDefaultsOnly,Category="Summoning")
	TArray<TSubclassOf<APawn>> MinionClasses;

	UPROPERTY(EditDefaultsOnly,Category="Summoning")
	float MinSpawnDistance = 60.f;
	
	UPROPERTY(EditDefaultsOnly,Category="Summoning")
	float MaxSpawnDistance = 200.f;

	UPROPERTY(EditDefaultsOnly,Category="Summoning")
	float SpawnSpread = 90.f;

	
	
};
