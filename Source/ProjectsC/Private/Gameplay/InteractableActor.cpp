// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/InteractableActor.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "UI/MyUserWidget.h"

// Sets default values
AInteractableActor::AInteractableActor()
{

	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = false; 


	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
    RootComponent = RootComp;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    BoxComponent->SetupAttachment(RootComp);

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    StaticMeshComponent->SetupAttachment(RootComp);
    StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
    WidgetComponent->SetupAttachment(RootComp);
    WidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    WidgetComponent->SetHiddenInGame(true);
    WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
    WidgetComponent->SetDrawAtDesiredSize(true);
    WidgetComponent->SetComponentTickEnabled(false); //Performace optimization

	
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
    UserWidget = Cast<UMyUserWidget>(WidgetComponent->GetUserWidgetObject());

    ensure(UserWidget);

        if (UserWidget) {
            UserWidget->SetPromptText("[E] Interact with " + InteractableName);
        }

}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   
}

void AInteractableActor::ShowInteractionWidget  ()
{
	WidgetComponent->SetHiddenInGame(false);
}

void AInteractableActor::HideInteractionWidget()
{
	WidgetComponent->SetHiddenInGame(true);

	//Wait for the next tick to allow the widget to be hidden before disabling the tick
    GetWorld()->GetTimerManager().SetTimerForNextTick([this]() 
        {
        WidgetComponent->SetComponentTickEnabled(false);
		});
}


void AInteractableActor::PerformAction()
{   
    // Implement the specific action for this interactable actor
    UE_LOG(LogTemp, Log, TEXT("Interacted with: %s"), *InteractableName);
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Interacted with " + InteractableName);
}