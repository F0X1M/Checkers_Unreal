#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlankSpawner.generated.h"

UCLASS()
class CHECKERS_API ABlankSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ABlankSpawner();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* StaticMeshComponent;

};
