// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

#include "JamUserWidget.h"
#include "JamTabStrip.generated.h"

class UJamTabButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectedTabChangedEvent, int32, SelectionIndex);

UCLASS()
class SHAREDJAMUI_API UJamTabStrip : public UJamUserWidget
{
	GENERATED_BODY()
	
public:
	// UUserWidget interface
	virtual void NativeConstruct() override;
	// End of UUserWidget interface

	// UJamUserWidget interface
	virtual void DesignTimeNativeConstruct() override;
	// End of UJamUserWidget interface

	UFUNCTION(BlueprintPure, Category="Button|TabStrip")
	int32 GetSelectedIndex();

	UFUNCTION(BlueprintCallable, Category="Button|TabStrip")
	void SetSelectedIndex(int32 NewIndex);

public:
	// Called when the tab selection is changed
	// Warning: Called in the designer too, so guard sensitive code with an IsDesignTime check
	UPROPERTY(BlueprintAssignable, Category="Button|TabStrip")
	FOnSelectedTabChangedEvent OnSelectionChanged;

protected:
	UPROPERTY(BlueprintReadOnly)
	TArray<UJamTabButton*> MyButtons;

private:
	UPROPERTY(EditAnywhere)
	int32 SelectedIndex;

private:
	void GatherButtons();
	void UpdateSelectionState();
};
