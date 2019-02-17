// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Components/ActorComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerPawn();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Controlled tank not found"));
	}
	else if (!PlayerTank && ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI tank controller is %s, but Player's tank not found"), *(ControlledTank->GetName()));
	}

	else if (PlayerTank && ControlledTank)
	{
		UE_LOG(LogTemp, Warning, 
			TEXT("AI tank controller \"%s\" found Player controller \"%s\""), 
			*(ControlledTank->GetName()), 
			*(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetPlayerPawn();
	if (!PlayerTank) { return; }
	else 
	{
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
}

// Returns the tank that belongs to this AI
ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Returns the first (0) player controller 
ATank * ATankAIController::GetPlayerPawn() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
