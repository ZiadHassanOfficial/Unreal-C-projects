// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Controllers/MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Pawns/MyPawn.h"



void AMyPlayerController::BeginPlay()

{
	Super::BeginPlay();
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
			ensure(FSlateDefaultInputMappingContext);
			if (DefaultInputMappingContext)
				InputSubsystem->AddMappingContext(DefaultInputMappingContext, 0);
		}
	}
	
	
	ensure(GetPawn());
	ControlledPawn = Cast<AMyPawn>(GetPawn());
	ensure(ControlledPawn);
}

	void AMyPlayerController::Move(const FInputActionValue & Instance)
	{
		FVector2D AxisValue = Instance.Get<FVector2D>();

		if (ControlledPawn)
		ControlledPawn->Move(AxisValue);
	}

	void AMyPlayerController::SetupInputComponent()
	{
		Super::SetupInputComponent();
		UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
		if (!Input)
			return;
		
		ensure(MoveAction);
		if(MoveAction)
			Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Move);

		ensure(LookAction);
		if (LookAction)
			Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Look);

		ensure(InteractAction);
		if (InteractAction)
			Input->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Interact);
	}