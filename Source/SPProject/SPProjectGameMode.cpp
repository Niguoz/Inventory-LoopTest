// Copyright Epic Games, Inc. All Rights Reserved.

#include "SPProjectGameMode.h"
#include "SPProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASPProjectGameMode::ASPProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
