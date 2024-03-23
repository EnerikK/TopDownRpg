// Hello


#include "AbilitySystem/Abilities/AuraFireBlast.h"

#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Actor/AuraFireBall.h"

FString UAuraFireBlast::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost());
	const float CoolDown = GetCooldown();
	
	return FString::Printf(TEXT(
			//Title
			"<Title>Fire Blast</>\n\n"

			//Level
			"<Small>Level : </>" "<Level>%d</>\n"
			//ManaCost
			"<Small>ManaCost : </><ManaCost>%.1f</>\n"
			//Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
			//Number of fireballs
			"<Default>Launches %d </>"
			"<Default>Fireballs in all directions , each coming back and </>"
			"<Default>exploding upon,causing  </>"
			
			//Damage
			"<Damage>%d</> <Default>Radial Damage</> \n\n"
			),
			//Values
			Level,
			ManaCost,
			CoolDown,
			NumFireBalls,
			ScaledDamage);
	
}
FString UAuraFireBlast::GetNextLevelDescription(int32 Level)
{
	return GetDescription(Level);
}
TArray<AAuraFireBall*> UAuraFireBlast::SpawnFireBalls()
{
	TArray<AAuraFireBall*> FireBalls;
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	TArray<FRotator> Rotators = UAuraAbilitySystemLibrary::EvenlySpacedRotators(Forward,FVector::UpVector,360.f,NumFireBalls);
	
	for(const FRotator& Rotator : Rotators)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(Location);
		SpawnTransform.SetRotation(Rotator.Quaternion());
		AAuraFireBall* FireBall = GetWorld()->SpawnActorDeferred<AAuraFireBall>(
			FireBallClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			CurrentActorInfo->PlayerController->GetPawn(),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
		
		FireBall->ReturnToActor = GetAvatarActorFromActorInfo();
		FireBall->DamageEffectParams = MakeDamageEffectParamsFromClassDefaults();
		FireBall->SetOwner(GetAvatarActorFromActorInfo());

		FireBall->ExplosionDamageParams = MakeDamageEffectParamsFromClassDefaults();
		
		FireBall->SetOwner(GetAvatarActorFromActorInfo());
		
		FireBalls.Add(FireBall);
		
		FireBall->FinishSpawning(SpawnTransform);
	}
	return FireBalls;
}
