// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

#include "JamUserWidget.h"
#include "JamTabButton.generated.h"

class UJamTabStrip;

UCLASS()
class SHAREDJAMUI_API UJamTabButton : public UJamUserWidget
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(BlueprintReadOnly)
	UJamTabStrip* ParentStrip;

	UPROPERTY(BlueprintReadOnly)
	int32 IndexInParent;
	
	// Can the button be selected
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCanButtonBeSelected;

	// Is the button currently considered selected?
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bIsButtonSelected;

	UFUNCTION(BlueprintNativeEvent)
	void SetIsSelected(bool bDrawAsSelected);
};
