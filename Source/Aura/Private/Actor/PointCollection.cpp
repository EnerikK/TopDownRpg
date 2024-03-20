// Hello


#include "Actor/PointCollection.h"

#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

APointCollection::APointCollection()
{
	PrimaryActorTick.bCanEverTick = false;

	Point0 = CreateDefaultSubobject<USceneComponent>("Point0");
	ImmutablePoints.Add(Point0);
	SetRootComponent(Point0);

	Point1 = CreateDefaultSubobject<USceneComponent>("Point1");
	ImmutablePoints.Add(Point1);
	Point1->SetupAttachment(GetRootComponent());

	Point2 = CreateDefaultSubobject<USceneComponent>("Point2");
	ImmutablePoints.Add(Point2);
	Point2->SetupAttachment(GetRootComponent());

	Point3 = CreateDefaultSubobject<USceneComponent>("Point3");
	ImmutablePoints.Add(Point3);
	Point3->SetupAttachment(GetRootComponent());
	
	Point4 = CreateDefaultSubobject<USceneComponent>("Point4");
	ImmutablePoints.Add(Point4);
	Point4->SetupAttachment(GetRootComponent());

	Point5 = CreateDefaultSubobject<USceneComponent>("Point5");
	ImmutablePoints.Add(Point5);
	Point5->SetupAttachment(GetRootComponent());
	
}

TArray<USceneComponent*> APointCollection::GetGroundPoints(const FVector& GroundLocation, int32 NumPoints,
	float YawOverride)
{
	checkf(ImmutablePoints.Num() >= NumPoints,TEXT("Attempted to access out of bounds"));
	TArray<USceneComponent*> ArrayCopy;
	for(USceneComponent* Point : ImmutablePoints)
	{
		if(ArrayCopy.Num() >= NumPoints) return ArrayCopy;

		if(Point != Point0)
		{
			FVector ToPoint = Point->GetComponentLocation() - Point0->GetComponentLocation();
			ToPoint = ToPoint.RotateAngleAxis(YawOverride,FVector::UpVector);
			Point->SetWorldLocation(Point0->GetComponentLocation() + ToPoint);
		}
		const FVector RaisedLocation = FVector(Point->GetComponentLocation().X,Point->GetComponentLocation().Y,Point->GetComponentLocation().Z + 500.f);
		const FVector LoweredLocation = FVector(Point->GetComponentLocation().X,Point->GetComponentLocation().Y,Point->GetComponentLocation().Z - 500.f);

		FHitResult HitResult;
		TArray<AActor*> IgnoreActors;
		UAuraAbilitySystemLibrary::GetLivePlayersWithinRadius(this,IgnoreActors,TArray<AActor*>(),1500.f,GetActorLocation());

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActors(IgnoreActors);
		GetWorld()->LineTraceSingleByProfile(HitResult,RaisedLocation,LoweredLocation,FName("BlockAll"),QueryParams);

		const FVector AdjustedLocation = FVector(Point->GetComponentLocation().X,Point->GetComponentLocation().Y,HitResult.ImpactPoint.Z);
		Point->SetWorldLocation(AdjustedLocation);
		Point->SetWorldRotation(UKismetMathLibrary::MakeRotFromZ(HitResult.ImpactPoint));
		
		ArrayCopy.Add(Point);
	}
	return ArrayCopy;
}
void APointCollection::BeginPlay()
{
	Super::BeginPlay();
	
}

