// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager.h"

// Sets default values for this component's properties
UManager::UManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	loopTimerHandler = loopTimeInSeconds;

	//FTimerHandle handle;
	//GetWorld()->GetTimerManager().Set
}


// Called every frame
void UManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	loopTimerHandler -= DeltaTime;

	//GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Time: %f"), loopTimerHandler));

	if (loopTimerHandler <= 0)
	{
		//FString level = GetWorld()->GetMapName();
		//UGameplayStatics::OpenLevel(GetWorld(), FName(level), TRAVEL_Absolute);
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
}

void UManager::CountDown()
{

}

