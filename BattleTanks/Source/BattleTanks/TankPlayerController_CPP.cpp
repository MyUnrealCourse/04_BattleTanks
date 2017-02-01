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

	UE_LOG(LogTemp, Warning, TEXT("Player Controller in Begin Play"));
}


ATank* ATankPlayerController_CPP::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

