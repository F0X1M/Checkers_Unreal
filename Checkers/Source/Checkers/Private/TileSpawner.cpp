
#include "TileSpawner.h"
#include "Kismet/GameplayStatics.h"

ATileSpawner::ATileSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATileSpawner::BuildBoard(const FVector CenteredLocation, const int X, const int Y)
{
	if (BoardTiles.Num() == 0)
	{
		BoardSize.X = X;
		BoardSize.Y = Y;

		for (auto OuterIndex{0}; OuterIndex<=Y-1;++OuterIndex)
		{
			for (auto InnerIndex{0}; InnerIndex<=X-1; ++InnerIndex)
			{
				float constexpr SectorSize = 400.f;  

				FVector SpawnLocation = 
					FVector(static_cast<float>(InnerIndex) - static_cast<float>(X) / 2.f, 
							static_cast<float>(OuterIndex) - static_cast<float>(Y) / 2.f, 0.f) * SectorSize * 1.f + CenteredLocation;

				FTransform SpawnTransform;
				SpawnTransform.SetLocation(SpawnLocation);

				if (TileClass)
				{
					AActor* TileToSpawn = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, TileClass.LoadSynchronous(), SpawnTransform);

					ATiles* Tile = Cast<ATiles>(TileToSpawn);
					
					if (static_cast<int>(InnerIndex) % 2 == 0)
					{
						if (static_cast<int>(OuterIndex) % 2 == 0)
							isWhite = true;
						else
							isWhite = false;
					}
					else {
						if (static_cast<int>(OuterIndex) % 2 == 0)
							isWhite = false;
						else
							isWhite = true;
					}

					if (Tile)
					{
						Tile->SetTileInfo(FTileInfo(InnerIndex, OuterIndex, 0, isWhite));
					}


					TileToSpawn->FinishSpawning(SpawnTransform);
					BoardTiles.Add(TileToSpawn);
					TileToSpawn->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
				}
			}
		}
	}
}

void ATileSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

