// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

#include "JamUserWidget.h"
#include "JamScreenBase.generated.h"

// The base class for a screen that can be added to the menu manager
UCLASS(Abstract)
class SHAREDJAMUI_API UJamScreenBase : public UJamUserWidget
{
	GENERATED_BODY()

public:
	UJamScreenBase(const FObjectInitializer& ObjectInitializer);

	// Called when this screen is added to the menu manager (native version, should call K2_OnScreenPushed at some point)
	virtual void OnScreenPushed();

	// Called when this screen is removed from the menu manager (native version, should call K2_OnScreenPopped at some point)
	virtual void OnScreenPopped();

	// Called when this screen becomes the top of the screen stack again (native version, should call K2_OnScreenUncovered at some point)
	virtual void OnScreenUncovered();

	// Called when this screen is covered by another screen (native version, should call K2_OnScreenCovered at some point)
	virtual void OnScreenCovered();

protected:
	// Called when this screen is added to the menu manager
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnScreenPushed"))
	void K2_OnScreenPushed() const;

	// Called when this screen is removed from the menu manager
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnScreenPopped"))
	void K2_OnScreenPopped() const;

	// Called when this screen becomes the top of the screen stack again
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnScreenOpened"))
	void K2_OnScreenUncovered() const;

	// Called when this screen is covered by another screen
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnScreenOpened"))
	void K2_OnScreenCovered() const;

protected:
	// Returns the optional animation to play when closing this screen (animates from open to closed)
	UFUNCTION(BlueprintNativeEvent)
	UWidgetAnimation* GetTransitionCloseAnimation();

	// The speed to play the closing animation (in reverse) when opening the screen
	UPROPERTY(EditDefaultsOnly, Category=Animation)
	float TransitionOpenAnimationSpeed;

	// The speed to play the closing animation when closing the screen
	UPROPERTY(EditDefaultsOnly, Category=Animation)
	float TransitionCloseAnimationSpeed;

	// If true, the screen animates from closed to opened when first added to the menu manager (the closing animation should be played in reverse)
	// Otherwise it starts open and the animation is only played if the screen is closed and then reopened
	UPROPERTY(EditDefaultsOnly, Category=Animation)
	bool bScreenAnimationStartsClosed;

private:
	bool bIsScreenAnimationClosedOrClosing;
};
