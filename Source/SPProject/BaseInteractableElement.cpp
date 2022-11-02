// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInteractableElement.h"
#include "SPProjectCharacter.h"
#include "InventoryComponent.h"

// Sets default values
ABaseInteractableElement::ABaseInteractableElement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ABaseInteractableElement::OverlapBegin);

	RootComponent = BoxCollider;
	StaticMesh->SetupAttachment(BoxCollider);
}

// Called when the game starts or when spawned
void ABaseInteractableElement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseInteractableElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseInteractableElement::OverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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
				FString typeString = UEnum::GetValueAsString(_typeObjNeeded.GetValue());
				_bFOundObject = FoundComp->SearchObject(typeString);
			}
		}
	}
}

