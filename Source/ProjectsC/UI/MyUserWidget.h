#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

class UTextBlock;

UCLASS()
class PROJECTSC_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetPromptText(const FString& InText);

protected:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> PromptText = nullptr;
};