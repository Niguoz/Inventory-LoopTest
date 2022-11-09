// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddObject(ABaseItem* object)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Added")));
	_inventoryList.Add(object);
}

bool UInventoryComponent::SearchObject(FString object)
{
	bool found = false;
	/*int32 index = _inventoryList.Find(object);

	if (index != INDEX_NONE)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Found")));
		_inventoryList.RemoveSingle(object);
		return true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Not Found")));
		return false;
	}*/
	if (_inventoryList.Num() > 0)
	{
		for (int i = 0; i < _inventoryList.Num(); i++)
		{
			TEnumAsByte<ItemTypes> type = _inventoryList[i]->_type;
			FString typeString = UEnum::GetValueAsString(type.GetValue());
			if (object == typeString)
			{
				_inventoryList.RemoveAt(i);
				found = true;
			}
		}
	}
	if (!found)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Not Found")));
		return false;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Found")));
		return true;
	}
}

