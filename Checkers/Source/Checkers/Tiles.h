// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tiles.generated.h"

USTRUCT(BlueprintType) struct FTileInfo
{
	GENERATED_BODY();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) int X{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) int Y{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) int Z{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) bool Color{};

	FTileInfo() = default;

	FTileInfo(int const NewX, int const NewY, int const NewZ, bool isWhite)
		: X(NewX), Y(NewY), Z(NewZ), Color(isWhite)
	{

	}

};

UCLASS()
class CHECKERS_API ATiles : public AActor
{
	GENERATED_BODY()
	
public:	
	ATiles();
	
	UFUNCTION(BlueprintImplementableEvent)
	void TileInfoEvent();
	
	void SetTileInfo(FTileInfo IntTileInfo)
	{
		TileInfo = IntTileInfo;
		TileInfoEvent();
	}

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = true))
		TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = true))
		FTileInfo TileInfo;
};
