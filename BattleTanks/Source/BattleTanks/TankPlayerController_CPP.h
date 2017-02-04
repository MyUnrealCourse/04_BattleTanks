// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController_CPP : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333;


	ATank* GetControlledTank() const;
	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;  //Runs every frame
};
