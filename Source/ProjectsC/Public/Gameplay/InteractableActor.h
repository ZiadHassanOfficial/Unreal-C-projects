#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

class USceneComponent;
class UBoxComponent;
class UStaticMeshComponent;
class UWidgetComponent;
class UMyUserWidget;

UCLASS()
class PROJECTSC_API AInteractableActor : public AActor
{
	GENERATED_BODY()

public:

	AInteractableActor();

	void PerformAction();
	void ShowInteractionWidget();
	void HideInteractionWidget();


protected:

	virtual void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;

	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> RootComp = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> BoxComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UWidgetComponent> WidgetComponent = nullptr;

	// The actual UserWidget instance created by WidgetComponent
	UPROPERTY()
	TObjectPtr<UMyUserWidget> UserWidget = nullptr;

	// Interaction
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactable")
	FString InteractableName = "";



public:

	// Called when the actor should face the player
	
};