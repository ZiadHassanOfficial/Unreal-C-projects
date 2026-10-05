// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext"
#include "InputAction.h"


UCLASS()

class PROJECTSC_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Instance);
	void MyPlayerController::Move(const FInputActionValue& Instance);
	virtual void SetupInputComponent() override;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input");
	TObjectPtr<UInputMappingContext> DefaultMappingContext = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input");
	TObjectPtr<UInputAction> MoveAction = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input");
	TObjectPtr<UInputAction> IntecartAction = nullptr;

	UPROPERTY()
	TObjectPtr<class AMyPawn> ControlledPawn = nullptr;
};

