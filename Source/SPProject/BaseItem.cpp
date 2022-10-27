// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"
#include "InventoryComponent.h"
#include "SPProjectCharacter.h"

// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::Test);
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseItem::Test(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Overlap")));

		ASPProjectCharacter* character = Cast<ASPProjectCharacter>(OtherActor);
		if (character != nullptr)
		{
			TArray<UInventoryComponent*> Comps;

			character->GetComponents(Comps);
			if (Comps.Num() > 0)
			{
				UInventoryComponent* FoundComp = Comps[0];
				FoundComp->AddObject(_type);
			}
		}
	}
}


