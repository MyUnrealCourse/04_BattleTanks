// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController_CPP.h"

void ATankPlayerController_CPP::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controlled Tank!"));
	}
	else
	{
		FString TankName;
		TankName = ControlledTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s is the tank controlled."), *TankName);
	}

}

void ATankPlayerController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Tick method is working"));
	AimTowardCrosshair();
}


ATank* ATankPlayerController_CPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController_CPP::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return;  }

	FVector HitLocation; //out parameter
	
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());

	//Get World location if line trace through crosshair 
	// if it hits the landscape
	if (GetSightRayHitLocation(HitLocation))
	{
		//start moving barrel toward location

	}
	else
	{
		return;
	}
		
}

bool ATankPlayerController_CPP::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY; //get the size of the viewport
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D((ViewportSizeX * CrosshairXLocation),(ViewportSizeY * CrosshairYLocation));
	//UE_LOG(LogTemp, Warning, TEXT("Screen Location: %s"), *ScreenLocation.ToString());
	
	// de-project screen position to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldPosition: %s"), *LookDirection.ToString());
	}

	//linetrace out through the crosshair
	//if we hit a world location
		//set HitLocation to this spot
		//return true
	//else retrurn false
	return true;
}

bool ATankPlayerController_CPP::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraPosition;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraPosition,
		LookDirection
	);
}
