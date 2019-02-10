// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKSALOT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
	
	void BeginPlay() override;
	

private:
	ATank* GetControlledTank() const;

	// Start moving the tank barrel where crosshair would intersect the world
	void AimTowardsCrosshair();
};
