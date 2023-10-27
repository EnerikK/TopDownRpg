// Hello

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	//Source Versions
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor =nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;
	
	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;


	//Target versions
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor =nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;
	
	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;


};
/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;// function to override to replicate variables 

	virtual  void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	//PrimaryAttributes

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Strength,Category="Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Strength);
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Intelligence,Category="Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Intelligence);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Resilience,Category="Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Resilience);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Vigor,Category="Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Vigor);

	//Secondary Attributes

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Armor,Category="Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Armor);
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_ArmorPenetration,Category="Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,ArmorPenetration);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_BlockChance,Category="Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,BlockChance);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_CriticalHitChance,Category="Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,CriticalHitChance);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_CriticalHitDamage,Category="Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,CriticalHitDamage);
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_CriticalHitResistance,Category="Secondary Attributes")
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,CriticalHitResistance);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_HealthRegeneration,Category="Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,HealthRegeneration);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_ManaRegeneration,Category="Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,ManaRegeneration);

	
	

	

	//Vital Attributes
	//Health Attribute
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Health,Category="Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Health);
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_MaxHealth,Category="Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,MaxHealth);
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth)const ;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)const;
	//End HealthAttribute And replication
	
	//Man Attribute
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Mana,Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Mana);
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_MaxMana,Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,MaxMana);
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana)const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)const;
	//End ManaAttribute And replication
	//Vital Attributes End

	//PrimaryAttributes
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength)const;
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)const;
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience)const;
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor)const;
	//Primary Attributes End

	//SecondaryAttributes
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor)const;
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration)const;
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance)const;
	
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance)const;
	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage)const;
	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance)const;
	
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration)const;
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration)const;
	//Secondary Attributes End

	
private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data,FEffectProperties& Props)const;


	
};
