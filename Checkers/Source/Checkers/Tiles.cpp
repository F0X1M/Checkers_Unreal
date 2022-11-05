#include "Tiles.h"

ATiles::ATiles()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	StaticMeshComponent->SetupAttachment(RootComponent);

}

void ATiles::BeginPlay()
{
	Super::BeginPlay();
	
}


