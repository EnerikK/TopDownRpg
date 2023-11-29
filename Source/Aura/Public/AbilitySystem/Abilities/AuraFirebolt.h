// Hello

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraProjectileSpell.h"
#include "AuraFirebolt.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraFirebolt : public UAuraProjectileSpell
{
	GENERATED_BODY()

public:
	
	virtual FString GetDescription(int32 Level) override;
	virtual FString GetNextLevelDescription(int32 Level) override;

	UFUNCTION(BlueprintCallable)
	void SpawnProjectiles(const FVector& ProjectileTargetLocation,const FGameplayTag& SocketTag,bool bOverridePitch ,float PitchOverride ,AActor* HomingTarget);

protected:

	UPROPERTY(EditDefaultsOnly , Category = "Firebolt")
	float ProjectileSpread = 90.f;

	UPROPERTY(EditDefaultsOnly , Category = "Firebolt")
	int32 MaxNumProjectiles = 4;

	UPROPERTY(EditDefaultsOnly , Category = "Firebolt")
	float HomingAccelerationMin = 1500.f;

	UPROPERTY(EditDefaultsOnly , Category = "Firebolt")
	float HomingAccelerationMax = 3000.f;

	UPROPERTY(EditDefaultsOnly , Category = "Firebolt")
	bool bLaunchHomingProjectiles= true;

	
};
