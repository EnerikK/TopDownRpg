// Hello


#include "AbilitySystem/Abilities/AuraFirebolt.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Actor/AuraProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

FString UAuraFirebolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost());
	const float CoolDown = GetCooldown();
	if(Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>Fire Bolt</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			
			"<Default>Launches a bolt of fire, "
			"exploding on impact and dealing : </>"
			//Damage
			"<Damage>%d</> <Default>Damage</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			ScaledDamage);
		
	}
	else
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>Fire Bolt</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//Number of fire bolts
			"<Default>Launches %d bolts of fire, "
			"exploding on impact and dealing : </>"
			//Damage
			"<Damage>%d</> <Default>Damage</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			FMath::Min(Level,NumProjectiles),
			ScaledDamage);
	}
	
}

FString UAuraFirebolt::GetNextLevelDescription(int32 Level)
{
	const float ManaCost = FMath::Abs(GetManaCost());
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float CoolDown = GetCooldown();
	return FString::Printf(TEXT(
			//Title
			"<Title>Next Level</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//Number of fire bolts
			"<Default>Launches %d bolts of fire, "
			"exploding on impact and dealing : </>"
			//Damage
			"<Damage>%d</> <Default>Damage</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			FMath::Min(Level,NumProjectiles),
			ScaledDamage);
}

void UAuraFirebolt::SpawnProjectiles(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag,
	bool bOverridePitch, float PitchOverride, AActor* HomingTarget)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if(!bIsServer)return;
	
	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(
		GetAvatarActorFromActorInfo(),
		SocketTag);
	FRotator Rotation = (ProjectileTargetLocation - SocketLocation).Rotation();
	if(bOverridePitch) Rotation.Pitch = PitchOverride;
	
	const FVector Forward = Rotation.Vector();
	
	const int32 EffectiveNumProjectiles = FMath::Min(NumProjectiles,GetAbilityLevel());
	TArray<FRotator> Rotations = UAuraAbilitySystemLibrary::EvenlySpacedRotators(Forward,FVector::UpVector,ProjectileSpread,EffectiveNumProjectiles);

	for(const FRotator& Rot : Rotations)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		SpawnTransform.SetRotation(Rot.Quaternion());

		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>
		(ProjectileClass,SpawnTransform,GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	
		Projectile->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults();
		
		if(HomingTarget && HomingTarget->Implements<UCombatInterface>())
		{
			Projectile->ProjectileMovement->HomingTargetComponent = HomingTarget->GetRootComponent();
			
		}
		else
		{
			//Homing targetComp is a weakobject which means when the projectile dies this new obj wont be cleaned up, look auraProjectile.h line32
			Projectile->HomingTargetSceneComponent = NewObject<USceneComponent>(USceneComponent::StaticClass());
			Projectile->HomingTargetSceneComponent->SetWorldLocation(ProjectileTargetLocation);
			Projectile->ProjectileMovement->HomingTargetComponent = Projectile->HomingTargetSceneComponent;
			
		}
		Projectile->ProjectileMovement->HomingAccelerationMagnitude = FMath::FRandRange(HomingAccelerationMin,HomingAccelerationMax);
		Projectile->ProjectileMovement->bIsHomingProjectile = bLaunchHomingProjectiles;
		Projectile->FinishSpawning(SpawnTransform);
	}
	
	
	
}
