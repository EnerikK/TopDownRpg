// Hello

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/CharacterClassInfo.h"
#include "AuraAbilitySystemLibrary.generated.h"

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

	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemLibrary|WidgetController", meta = (DefaultToSelf = "WorldContextObject"))
	static bool MakeWidgetControllerParams(const UObject* WorldContextObject, FWidgetControllerParams& OutWCParams, AAuraHUD*& OutAuraHUD);
	
	UFUNCTION(BlueprintPure,Category = "AuraAbilitySystemLibrary | WidgeController")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure,Category = "AuraAbilitySystemLibrary | WidgeController")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable,Category = "AuraAbilitySystemLibrary | CharacterClassDefaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject,ECharacterClass CharacterClass ,float Level,UAbilitySystemComponent* ASC);
	
};
