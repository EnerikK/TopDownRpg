// Hello


#include "Actor/MagicCircle.h"
#include "Components/DecalComponent.h"

AMagicCircle::AMagicCircle()
{
	PrimaryActorTick.bCanEverTick = true;

	MagiCircleDecal = CreateDefaultSubobject<UDecalComponent>("MagicCircleDecal");
	MagiCircleDecal->SetupAttachment(GetRootComponent());

}

void AMagicCircle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMagicCircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

