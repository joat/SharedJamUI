// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"
#include "JamUserWidget.h"
#include "JamMenuManager.h"

void UJamUserWidget::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	NativePreConstruct();
	if (IsDesignTime())
	{
		DesignTimeNativeConstruct();
	}
}

void UJamUserWidget::DesignTimeNativeConstruct()
{
	DesignTimeConstruct();
}

void UJamUserWidget::NativePreConstruct()
{
	PreConstruct(IsDesignTime());
}

AJamMenuManager* UJamUserWidget::GetMenuManager()
{
	const FLocalPlayerContext& Context = GetPlayerContext();
	return Context.GetHUD<AJamMenuManager>(false);
}
