// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	//Aim towards player
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	if (ensure(PlayerTank && ControlledTank)) {
		//Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm

		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//Limit firing rate
		ControlledTank->Fire();
	}
}
