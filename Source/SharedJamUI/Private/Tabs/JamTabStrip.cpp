// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"
#include "JamTabStrip.h"
#include "JamTabButton.h"
#include "Blueprint/WidgetTree.h"

void UJamTabStrip::NativeConstruct()
{
	Super::NativeConstruct();

	GatherButtons();
	UpdateSelectionState();
}

void UJamTabStrip::DesignTimeNativeConstruct()
{
	Super::DesignTimeNativeConstruct();

	GatherButtons();
	UpdateSelectionState();
}

int32 UJamTabStrip::GetSelectedIndex()
{
	return SelectedIndex;
}

void UJamTabStrip::SetSelectedIndex(int32 NewIndex)
{
	const int32 LastSelectedIndex = INDEX_NONE;
	if (MyButtons.IsValidIndex(NewIndex))
	{
		//@TODO: See if the button actually allows selection
		SelectedIndex = NewIndex;
	}
	else
	{
		SelectedIndex = INDEX_NONE;
	}

	if (SelectedIndex != LastSelectedIndex)
	{
		UpdateSelectionState();
	}
}

void UJamTabStrip::UpdateSelectionState()
{
	for (UJamTabButton* Button : MyButtons)
	{
		const bool bButtonSelected = Button->IndexInParent == SelectedIndex;
		Button->SetIsSelected(bButtonSelected);
	}

	OnSelectionChanged.Broadcast(SelectedIndex);
}

void UJamTabStrip::GatherButtons()
{
	MyButtons.Reset();
	UJamTabStrip* ParentStrip = this;
	WidgetTree->ForEachWidget([ParentStrip](UWidget* Widget)
	{
		if (UJamTabButton* Button = Cast<UJamTabButton>(Widget))
		{
			Button->ParentStrip = ParentStrip;
			Button->IndexInParent = ParentStrip->MyButtons.Num();
			ParentStrip->MyButtons.Add(Button);
		}
	});
}
