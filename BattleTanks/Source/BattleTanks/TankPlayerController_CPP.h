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
	ATank* GetControlledTank() const;
	void AimTowardCrosshair();

	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;  //Runs every frame
};
