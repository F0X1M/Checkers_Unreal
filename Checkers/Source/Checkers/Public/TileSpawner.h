#pragma once

#include "CoreMinimal.h"
#include "../Tiles.h"
#include "GameFramework/Actor.h"
#include "TileSpawner.generated.h"

UCLASS()
class CHECKERS_API ATileSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ATileSpawner();

	UFUNCTION(BlueprintCallable)
		void BuildBoard(const FVector CenteredLocation, const int X, const int Y);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FVector2D BoardSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<AActor>> BoardTiles;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<ATiles> TileClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool isWhite;

};
