// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* MyPlayerTank = GetPlayerTank();
	ATank* ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI Controlled Tank found!"));
	}
	else
	{
		if (!MyPlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("No Player Controlled Tank found!"));
		}
		else
		{
			FString TankName;
			FString PlayerTankName;

			TankName = ControlledTank->GetName();
			PlayerTankName = MyPlayerTank->GetName();
			UE_LOG(LogTemp, Warning, TEXT("%s is the tank targeted by %s."), *PlayerTankName, *TankName);
		}
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank * ATankAIController::GetPlayerTank() const
{

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerTank);
	//return nullptr;
}
