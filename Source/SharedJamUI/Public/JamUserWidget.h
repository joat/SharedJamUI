// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

#include "Blueprint/UserWidget.h"
#include "JamUserWidget.generated.h"

class AJamMenuManager;

// Custom base widget with some added utility methods
UCLASS()
class SHAREDJAMUI_API UJamUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// UWidget interface
	virtual void OnWidgetRebuilt() override;
	// End of UWidget interface

	/**
	 * Called before Construct() is called in the game, or called instead of Construct() in the designer
	 * Warning: This can be called in the designer, where the game is not running, so accessing game types
	 * like the player controller or game instance will fail!
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="User Interface", meta=(Keywords="Begin Play"))
	void PreConstruct(bool bInDesigner);

	/**
	 * Called after the underlying slate widget is constructed in the designer.  Warning: The game is not running in the designer
	 * so accessing game types like the player controller or game instance will fail!
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="User Interface", meta=(Keywords="Begin Play"))
	void DesignTimeConstruct();

	UFUNCTION(BlueprintPure, Category="User Interface", meta=(DisplayName="IsDesignTime"))
	bool K2_IsDesignTime() const
	{
		return IsDesignTime();
	}

	/** Returns the menu manager associated with the player that is viewing this widget (or player 1) */
	UFUNCTION(BlueprintCallable, Category="User Interface")
	AJamMenuManager* GetMenuManager();

protected:
	/**
	 * Called before Construct() is called in the game, or called instead of Construct() in the designer
	 * Warning: This can be called in the designer, where the game is not running, so accessing game types
	 * like the player controller or game instance will fail!
	 */
	virtual void NativePreConstruct();

	/**
	 * Called after the underlying slate widget is constructed in the designer.  Warning: The game is not running in the designer
	 * so accessing game types like the player controller or game instance will fail!
	 */
	virtual void DesignTimeNativeConstruct();
};
