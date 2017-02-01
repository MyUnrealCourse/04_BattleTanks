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
	
	UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());

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
	//linetrace out through the crosshair
	//if we hit a world location
		//set HitLocation to this spot
		//return true
	//else retrurn false
}