#include "MyPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MyPawn.h"


void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (DefaultMappingContext)
            {
                Subsystem->AddMappingContext(DefaultMappingContext, 0);
            }
        }
    }

    ControlledPawn = Cast<AMyPawn>(GetPawn());

    ensure(ControlledPawn);
}


void AMyPlayerController::Move(const FInputActionValue& Instance)
{
    const FVector2D AxisValue = Instance.Get<FVector2D>();

    if (ControlledPawn)
    {
        ControlledPawn->Move(AxisValue);
    }
}


void AMyPlayerController::Look(const FInputActionValue& Instance)
{
    const FVector2D AxisValue = Instance.Get<FVector2D>();

    AddYawInput(AxisValue.X);
    AddPitchInput(AxisValue.Y);
}


void AMyPlayerController::Interact(const FInputActionInstance& Instance)
{
    ControlledPawn->TryInteract();
}


void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UEnhancedInputComponent* Input =
        Cast<UEnhancedInputComponent>(InputComponent);

    if (!Input)
    {
        return;
    }

    if (MoveAction)
    {
        Input->BindAction(
            MoveAction,
            ETriggerEvent::Triggered,
            this,
            &AMyPlayerController::Move
        );
    }

    if (LookAction)
    {
        Input->BindAction(
            LookAction,
            ETriggerEvent::Triggered,
            this,
            &AMyPlayerController::Look
        );
    }
    if( InteractAction)
    {
        Input->BindAction(
            InteractAction,
            ETriggerEvent::Triggered,
            this,
            &AMyPlayerController::Interact
        );
	}
}
   


    
    
