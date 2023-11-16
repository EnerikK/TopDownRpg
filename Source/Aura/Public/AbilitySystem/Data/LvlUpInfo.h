// Hello

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LvlUpInfo.generated.h"

USTRUCT(BlueprintType)
struct FAuraLevelUpInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	int32 LevelUpRequirement = 0;

	UPROPERTY(EditDefaultsOnly)
	int32 AttributePointAward = 1;
	
	UPROPERTY(EditDefaultsOnly)
	int32 SpellPointAward = 1;

	
	
};
/**
 * 
 */
UCLASS()
class AURA_API ULvlUpInfo : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly)
	TArray<FAuraLevelUpInfo> LevelUpInformation;

	int32 FindLevelForXp(int32 XP)const;
};
