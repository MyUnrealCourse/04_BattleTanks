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
	//Get World location of line trace through crosshair 
	// if it hits the landscape
	if (GetSightRayHitLocation(HitLocation))
	{
		//start moving barrel toward location
		UE_LOG(LogTemp, Warning, TEXT("HitPosition: %s"), *HitLocation.ToString());
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
	
	// de-project screen position to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Linetrace in the look direction to see if it hits anything
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController_CPP::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector LineStart = PlayerCameraManager->GetCameraLocation();
	FVector LineEnd = LineStart + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult, 
			LineStart, 
			LineEnd, 
			ECollisionChannel::ECC_Visibility))
	{
		//set the hit location
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
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
