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

	UE_LOG(LogTemp, Warning, TEXT("Tick method is working"));
}


ATank* ATankPlayerController_CPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController_CPP::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return;  }

	//Get World location if line trace through crosshair 
	// if it hits the landscape
		//start moving barrel toward location
}