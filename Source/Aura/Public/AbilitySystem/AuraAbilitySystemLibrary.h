// Hello

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilityTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/CharacterClassInfo.h"
#include "AuraAbilitySystemLibrary.generated.h"

class UAbilityInfo;
class USpellMenuWidgetController;
enum class ECharacterClass : uint8;
class AAuraHUD;
struct FWidgetControllerParams;
class UAttributeMenuWidgetController;
class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/*WidgetController*/
	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemLibrary|WidgetController", meta = (DefaultToSelf = "WorldContextObject"))
	static bool MakeWidgetControllerParams(const UObject* WorldContextObject, FWidgetControllerParams& OutWCParams, AAuraHUD*& OutAuraHUD);
	
	UFUNCTION(BlueprintPure,Category = "AuraAbilitySystemLibrary | WidgeController" , meta = (DefaultToSelf = "WorldContextObject"))
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure,Category = "AuraAbilitySystemLibrary | WidgeController", meta = (DefaultToSelf = "WorldContextObject"))
	static USpellMenuWidgetController* GetSpellMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure,Category = "AuraAbilitySystemLibrary | WidgeController", meta = (DefaultToSelf = "WorldContextObject"))
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);

	/*AbilitySystemClass*/
	UFUNCTION(BlueprintCallable,Category = "AuraAbilitySystemLibrary | CharacterClassDefaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject,ECharacterClass CharacterClass ,float Level,UAbilitySystemComponent* ASC);

	UFUNCTION(BlueprintCallable,Category = "AuraAbilitySystemLibrary | CharacterClassDefaults")
	static void GiveStartUpAbilities(const UObject* WorldContextObject,UAbilitySystemComponent* ASC,ECharacterClass CharacterClass);

	UFUNCTION(BlueprintCallable,Category = "AuraAbilitySystemLibrary | CharacterClassDefaults")
	static UCharacterClassInfo* GetCharacterClassInfo(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable,Category = "AuraAbilitySystemLibrary | CharacterClassDefaults")
	static UAbilityInfo* GetAbilityInfo(const UObject* WorldContextObject);

	/*Effect Context Getters*/
	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static bool IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static bool IsSuccessfulDebuff(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static float GetDebuffDamage(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static float GetDebuffDuration(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static float GetDebuffFrequency(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static FGameplayTag GetDamageType(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static FVector GetDeathImpulse(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static FVector GetKnockbackForce(const FGameplayEffectContextHandle& EffectContextHandle);
	
	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static bool IsCriticalHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static bool IsRadialDamage(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static float GetRadialDamageInnerRadius(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static float GetRadialDamageOuterRadius(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static FVector GetRadialDamageOrigin(const FGameplayEffectContextHandle& EffectContextHandle);

	/**Effect Context Setters*/
	
	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetIsBlockedHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,bool bInIsBlockedHit);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetIsCriticalHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,bool bInIsCriticalHit);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetIsSuccessfulDebuff(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,bool bInSuccessfulDebuff);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetDebuffDamage(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,float InDamage);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetDebuffDuration(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,float InDuration);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetDebuffFrequency(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,float InFrequency);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetDamageType(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle,const FGameplayTag& InDamageType);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetDeathImpulse(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle,const FVector& InImpulse);
	
	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetKnockbackForce(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle,const FVector& InForce);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetIsRadialDamage(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,bool bInIsRadialDamage);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetRadialDamageInnerRadius(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,float InInnerRadius);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetRadialDamageOuterRadius(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle,float InOuterRadius);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void SetRadialDamageOrigin(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle,const FVector& InOrigin);


	/*Gameplay Mechanics*/
	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayMechanics ")
	static void GetLivePlayersWithinRadius(const UObject* WorldContextObject,TArray<AActor*>& OutOverlappingActors,const TArray<AActor*>& ActorsToIgnore,float Radius,const FVector& SphereOrigin);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayEffects ")
	static void GetClosestTarget(int32 MaxTargets , const TArray<AActor*>& Actors , TArray<AActor*>& OutClosestTargets , const FVector& Origin);
	
	UFUNCTION(BlueprintPure, Category= "AuraAbilitySystemLibrary | GameplayMechanics ")
	static bool IsNotFriend(AActor* FirstActor , AActor* SecondActor);
	
	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | DamageEffect ")
	static FGameplayEffectContextHandle ApplyDamageEffect(const FDamageEffectParams& DamageEffectParams);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayMechanics ")
	static TArray<FRotator> EvenlySpacedRotators(const FVector& Forward , const FVector& Axis , float Spread,int32 NumRotators);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayMechanics ")
	static TArray<FVector> EvenlyRotatedVectors(const FVector& Forward , const FVector& Axis, float Spread, int32 NumVectors);

	static int32 GetXPRewardForClassAndLevel(const UObject* WorldContextObject , ECharacterClass CharacterClass , int32 CharacterLevel);
	
	/*Damage EffectParams*/
	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayMechanics ")
	static void SetIsRadialDamageEffectParam(UPARAM(ref)FDamageEffectParams& DamageEffectParams,bool bIsRadial,float InnerRadius , float OuterRadius,FVector Origin);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayMechanics ")
	static void SetKnockBackDirection(UPARAM(ref)FDamageEffectParams& DamageEffectParams,FVector KnockBackDirection,float Magnitude = 0.f);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayMechanics ")
	static void SetDeathImpulseDirection(UPARAM(ref)FDamageEffectParams& DamageEffectParams,FVector ImpulseDirection,float Magnitude = 0.f);

	UFUNCTION(BlueprintCallable, Category= "AuraAbilitySystemLibrary | GameplayMechanics ")
	static void SetTargetEffectParamsASC(UPARAM(ref)FDamageEffectParams& DamageEffectParams,UAbilitySystemComponent* InASC);


	
};
