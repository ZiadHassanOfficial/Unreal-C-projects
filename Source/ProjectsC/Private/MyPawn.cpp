// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/ArrowComponent.h"
#include "Gameplay/InteractableActor.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComp;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(RootComponent);
	CameraComp->bUsePawnControlRotation = true; //Use the pawn's control rotation to rotate the camera

	MovementComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

	PawnDirectionArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("PawnDirectionArrow"));
	PawnDirectionArrow->SetupAttachment(RootComponent);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true; //Use the pawn's control rotation to rotate the pawn
	bUseControllerRotationRoll = false;

}


// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPawn::Move(const FVector2D& MovementInput)
{
	AddMovementInput(GetActorForwardVector(), MovementInput.Y);
	AddMovementInput(GetActorRightVector(), MovementInput.X);

}

bool AMyPawn::PerformInteractionTrace(FHitResult& OutHitResult) const
{
	FVector StartPoint = CameraComp->GetComponentLocation();
	FVector EndPoint = StartPoint + (CameraComp->GetForwardVector() * InteractionTraceDistance);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // Ignore the pawn itself

	const bool bHit = GetWorld()->LineTraceSingleByChannel(OutHitResult, StartPoint, EndPoint, ECollisionChannel::ECC_Visibility, Params);
	return bHit;
}

void AMyPawn::UpdateCurrentInteractable()
{
	FHitResult HitResult;
	AInteractableActor* NewInteractable = nullptr;
	if (PerformInteractionTrace(HitResult)) {
		NewInteractable = Cast<AInteractableActor>(HitResult.GetActor());
		if (CurrentInteractable == NewInteractable) {
			return; // No change in interactable
		}
		if (CurrentInteractable) {
			CurrentInteractable->HideInteractionWidget();
		}
		CurrentInteractable = NewInteractable;
		if (NewInteractable) {
			NewInteractable->ShowInteractionWidget();
		}
	}
}
void AMyPawn::TryInteract()
{
	if (CurrentInteractable) {
		CurrentInteractable->PerformAction();
	}
}



/*void AMyPawn::UpdateCurrentInteractable()
{
	FHitResult HitResult;
	FVector StartPoint = CameraComp->GetComponentLocation();
	FVector EndPoint = StartPoint + (CameraComp->GetForwardVector() * InteractionTraceDistance);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // Ignore the pawn itself
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartPoint, EndPoint, ECollisionChannel::ECC_Visibility, Params)) {

		if (AInteractableActor* DetectedInteractable = Cast<AInteractableActor>(HitResult.GetActor())) {

			if (CurrentInteractable == DetectedInteractable)
			{
				return;
			}
			CurrentInteractable->HideInteractionWidget();
			CurrentInteractable = DetectedInteractable;
			DetectedInteractable->ShowInteractionWidget();
		}
		else if (CurrentInteractable) {
			CurrentInteractable->HideInteractionWidget();
			CurrentInteractable = nullptr;
		}
	}
	else if (CurrentInteractable) {
		CurrentInteractable->HideInteractionWidget();
		CurrentInteractable = nullptr;
	}
}*/


