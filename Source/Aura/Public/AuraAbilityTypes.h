#pragma once


#include "GameplayEffectTypes.h"
#include "AuraAbilityTypes.generated.h"




USTRUCT(BlueprintType)
struct FAuraGameplayEffectsContext : public FGameplayEffectContext
{
	GENERATED_BODY()
	

public:

	bool IsCriticalHit() const {return bIsCriticalHit;}
	bool IsBlockedHit() const {return bIsBlockedHit;}

	void SetIsCriticalHit(bool bInIsCriticalHit) {bIsCriticalHit = bInIsCriticalHit;}
	void SetIsBlockedHit(bool bInIsBlockedHit) {bIsBlockedHit = bInIsBlockedHit;}

	virtual UScriptStruct* GetScriptStruct() const override
	{
		return StaticStruct();
	}

	virtual FAuraGameplayEffectsContext* Duplicate() const
	{
		FAuraGameplayEffectsContext* NewContext = new FAuraGameplayEffectsContext();
		*NewContext = *this;
		if (GetHitResult())
		{
			// Does a deep copy of the hit result
			NewContext->AddHitResult(*GetHitResult(), true);
		}
		return NewContext;
	}

	virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess) override;
	
	

protected:
	
	UPROPERTY()
	bool bIsBlockedHit = false;
	
	UPROPERTY()
	bool bIsCriticalHit = false;
	
};

template<>
struct TStructOpsTypeTraits<FAuraGameplayEffectsContext> : public TStructOpsTypeTraitsBase2<FAuraGameplayEffectsContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true
	};
	
};