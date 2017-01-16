// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"
#include "JamScreenBase.h"
#include "Animation/UMGSequencePlayer.h"

UJamScreenBase::UJamScreenBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, TransitionOpenAnimationSpeed(1.0f)
	, TransitionCloseAnimationSpeed(1.0f)
{
}

void UJamScreenBase::OnScreenPushed()
{
	bIsScreenAnimationClosedOrClosing = bScreenAnimationStartsClosed;

	K2_OnScreenPushed();
}

void UJamScreenBase::OnScreenPopped()
{
	K2_OnScreenPopped();
}

void UJamScreenBase::OnScreenUncovered()
{
	SetVisibility(ESlateVisibility::Visible);
	const UWidgetAnimation* TransitionCloseAnimation = GetTransitionCloseAnimation();
	if ((TransitionCloseAnimation != nullptr) && bIsScreenAnimationClosedOrClosing)
	{
		bIsScreenAnimationClosedOrClosing = false;
		if (UUMGSequencePlayer* TransitionPlayer = GetOrAddPlayer(TransitionCloseAnimation))
		{
			if (TransitionPlayer->GetPlaybackStatus() == EMovieScenePlayerStatus::Stopped)
			{
				TransitionPlayer->Play(0.0f, 1, EUMGSequencePlayMode::Reverse, TransitionOpenAnimationSpeed);
			}
			else
			{
				TransitionPlayer->Reverse();
			}
		}
	}

	K2_OnScreenUncovered();
}

void UJamScreenBase::OnScreenCovered()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
	const UWidgetAnimation* TransitionCloseAnimation = GetTransitionCloseAnimation();
	if ((TransitionCloseAnimation != nullptr) && !bIsScreenAnimationClosedOrClosing)
	{
		bIsScreenAnimationClosedOrClosing = true;
		if (UUMGSequencePlayer* TransitionPlayer = GetOrAddPlayer(TransitionCloseAnimation))
		{
			if (TransitionPlayer->GetPlaybackStatus() == EMovieScenePlayerStatus::Stopped)
			{
				TransitionPlayer->Play(0.0f, 1, EUMGSequencePlayMode::Forward, TransitionCloseAnimationSpeed);
			}
			else
			{
				TransitionPlayer->Reverse();
			}
		}
	}

	K2_OnScreenCovered();
}

UWidgetAnimation* UJamScreenBase::GetTransitionCloseAnimation_Implementation()
{
	return nullptr;
}