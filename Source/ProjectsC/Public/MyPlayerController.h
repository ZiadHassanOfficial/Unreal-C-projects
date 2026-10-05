#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "MyPlayerController.generated.h"

class AMyPawn;

UCLASS()
class PROJECTSC_API AMyPlayerController : public APlayerController
{
    GENERATED_BODY()

protected:

    virtual void BeginPlay() override;

    virtual void SetupInputComponent() override;

    void Move(const FInputActionValue& Instance);

    void Look(const FInputActionValue& Instance);

    void Interact(const FInputActionValue& Instance);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputMappingContext> DefaultMappingContext = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> MoveAction = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> LookAction = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> InteractAction = nullptr;

    UPROPERTY()
    TObjectPtr<AMyPawn> ControlledPawn = nullptr;
};