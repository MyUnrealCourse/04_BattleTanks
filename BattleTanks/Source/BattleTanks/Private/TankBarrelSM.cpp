// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrelSM.h"

void UTankBarrelSM::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate called at Speed %f"), DegreesPerSecond);
}

