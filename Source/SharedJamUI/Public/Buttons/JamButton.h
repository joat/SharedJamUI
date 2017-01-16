// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

class UJamButtonStyle;

#include "JamUserWidget.h"
#include "JamButton.generated.h"

UCLASS()
class SHAREDJAMUI_API UJamButton : public UJamUserWidget
{
	GENERATED_BODY()
	
public:	
	UJamButton(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UJamButtonStyle* ButtonStyle;
};
