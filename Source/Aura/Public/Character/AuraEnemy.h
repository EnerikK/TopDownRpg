// Hello

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"


class UWidgetComponent;
class UBehaviorTree;
class AAuraAIController;
/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	virtual void PossessedBy(AController* NewController) override;

	//Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//End EnemyInterface


	/**Combat Interface   */
	virtual int32 GetPlayerLevel_Implementation() override;
	virtual void Die(const FVector& DeathImpulse) override;
	virtual void SetCombatTarget_Implementation(AActor* InCombatTarget) override;
	virtual AActor* GetCombatTarget_Implementation() const override;

	/**  End combat interface         */

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;


	void HitReactTagChanged(const FGameplayTag CallBackTag,int32 NewCount);

	UPROPERTY(BlueprintReadOnly,Category="Combat")
	bool bHitReacting = false;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combat")
	float LifeSpan = 5;

	UPROPERTY(BlueprintReadWrite,Category="Combat")
	TObjectPtr<AActor> CombatTarget;
	
protected:

	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeDefaultAttributes()const override;
	virtual void StunnedTagChanged(const FGameplayTag CallbackTag, int32 NewCount) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character Class Defaults")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;

	/*
	 * AI
	 */
	UPROPERTY(EditAnywhere,Category="AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<AAuraAIController> AuraAIController;


};
