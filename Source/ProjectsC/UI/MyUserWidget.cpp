#include "UI/MyUserWidget.h"

#include "Components/TextBlock.h"

void UMyUserWidget::SetPromptText(const FString& InText)
{
	ensure(PromptText);

	if (PromptText)
	{
		PromptText->SetText(FText::FromString(InText));
	}
}