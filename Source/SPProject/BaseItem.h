// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BaseItem.generated.h"

UENUM()
enum ItemTypes
{
	Gear UMETA(DisplayName = "Gear"),
	Letter UMETA(DisplayName = "Letter"),
	Pincer UMETA(DisplayName = "Pincer"),
	Key UMETA(DisplayName = "Key"),
};

UCLASS()
class SPPROJECT_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* BoxCollider;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		TEnumAsByte<ItemTypes> _type;

	UFUNCTION()
	void StartOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
