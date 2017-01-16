// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

class UJamScreenBase;

#include "GameFramework/HUD.h"
#include "JamMenuManager.generated.h"

UENUM(BlueprintType)
enum class EJamScreenActivationMode : uint8
{
	// Show screens below me
	Transparent,

	// Do not show screens below me, but don't remove them either
	Opaque,

	// Remove any active screens before showing me
	Exclusive
};

USTRUCT()
struct FJamScreenStackEntry
{
	GENERATED_BODY()

	UPROPERTY()
	UJamScreenBase* Screen;

	UPROPERTY()
	EJamScreenActivationMode ActivationMode;
};

/**
 * 
 */
UCLASS()
class SHAREDJAMUI_API AJamMenuManager : public AHUD
{
	GENERATED_BODY()

public:
	// Add a new screen to the menu stack, optionally removing or hiding screens below the top (based on the ActivationMode)
	UFUNCTION(BlueprintCallable, Category=UI, meta=(Keywords="Push AddScreen"))
	void ActivateScreen(UJamScreenBase* ScreenToAdd, EJamScreenActivationMode ActivationMode);

	// Remove the specified screen regardless of where it is in the stack of screens
	UFUNCTION(BlueprintCallable, Category=UI, meta=(Keywords="Pop RemoveScreen"))
	void RemoveScreen(UJamScreenBase* ScreenToRemove);

	// Remove the top most screen
	UFUNCTION(BlueprintCallable, Category=UI)
	void PopScreen();

protected:
	void RemoveScreenInternal(const FJamScreenStackEntry& ScreenRecord);

protected:
	UPROPERTY()
	TArray<FJamScreenStackEntry> ScreenStack;
};
