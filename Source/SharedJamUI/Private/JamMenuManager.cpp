// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"
#include "JamMenuManager.h"
#include "JamScreenBase.h"

void AJamMenuManager::ActivateScreen(UJamScreenBase* ScreenToAdd, EJamScreenActivationMode ActivationMode)
{
	if (ScreenToAdd != nullptr)
	{
		if (ActivationMode == EJamScreenActivationMode::Exclusive)
		{
			// Close the existing screens
			while (ScreenStack.Num())
			{
				FJamScreenStackEntry DyingEntry = ScreenStack.Pop(/*bAllowShrinking=*/ false);
				RemoveScreenInternal(DyingEntry);
			}
			ActivationMode = EJamScreenActivationMode::Opaque;
		}

		if (ScreenStack.Num() > 0)
		{
			// Let the topmost screen know it isn't topmost anymore
			ScreenStack.Last().Screen->OnScreenCovered();
		}

		if (ActivationMode == EJamScreenActivationMode::Opaque)
		{
			// Hide the existing screens
			for (int32 ExistingIndex = ScreenStack.Num() - 1; (ExistingIndex >= 0); --ExistingIndex)
			{
				UJamScreenBase* Screen = ScreenStack[ExistingIndex].Screen;
				if (Screen->GetVisibility() != ESlateVisibility::Collapsed)
				{
					Screen->SetVisibility(ESlateVisibility::Collapsed);
				}
			}
		}

		// Create the new entry
		FJamScreenStackEntry NewScreen;
		NewScreen.Screen = ScreenToAdd;
		NewScreen.ActivationMode = ActivationMode;
		ScreenStack.Add(NewScreen);

		ScreenToAdd->OnScreenPushed();
		ScreenToAdd->OnScreenUncovered();
		ScreenToAdd->AddToPlayerScreen();
	}
}

void AJamMenuManager::RemoveScreen(UJamScreenBase* ScreenToRemove)
{
	const int32 ScreenIndex = ScreenStack.IndexOfByPredicate([ScreenToRemove](const FJamScreenStackEntry& Entry) { return Entry.Screen == ScreenToRemove; });
	if (ScreenIndex != INDEX_NONE)
	{
		FJamScreenStackEntry DyingEntry = ScreenStack[ScreenIndex];
		ScreenStack.RemoveAt(ScreenIndex, /*Count=*/ 1, /*bAllowShrinking=*/ false);
		RemoveScreenInternal(DyingEntry);

		//@TODO: Recompute visibility for remaining stack entries
		if (ScreenStack.Num() > 0)
		{
			// Restore visibility on remaining entries below the topmost entry until we run into an opaque one
			const int32 LowestOpaqueIndex = ScreenStack.FindLastByPredicate([](const FJamScreenStackEntry& Entry) { return Entry.ActivationMode == EJamScreenActivationMode::Opaque; });
			const int32 StartIndex = (LowestOpaqueIndex == INDEX_NONE) ? 0 : LowestOpaqueIndex;

			for (int32 Index = StartIndex; Index < ScreenStack.Num() - 1; ++Index)
			{
				ScreenStack[Index].Screen->SetVisibility(ESlateVisibility::HitTestInvisible);
			}

			// Uncover the topmost entry
			ScreenStack.Last().Screen->OnScreenUncovered();
		}
	}
}

void AJamMenuManager::PopScreen()
{
	if (ScreenStack.Num() > 0)
	{
		RemoveScreen(ScreenStack.Top().Screen);
	}
}

void AJamMenuManager::RemoveScreenInternal(const FJamScreenStackEntry& ScreenRecord)
{
	check(ScreenRecord.Screen);
	ScreenRecord.Screen->OnScreenCovered();
	ScreenRecord.Screen->OnScreenPopped();

	ScreenRecord.Screen->RemoveFromParent();
}
