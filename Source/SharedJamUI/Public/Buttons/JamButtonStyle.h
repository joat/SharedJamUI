// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

#include "Engine/DataAsset.h"
#include "JamButtonStyle.generated.h"

UCLASS()
class SHAREDJAMUI_API UJamButtonStyle : public UDataAsset
{
	GENERATED_BODY()
	
public:	
	UJamButtonStyle();

	/** The button style used at runtime */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance", meta=( DisplayName="Style" ))
	FButtonStyle WidgetStyle;

	/** The color multiplier for the button content */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance", meta=( sRGB="true" ))
	FLinearColor ColorAndOpacity;
	
	/** The color multiplier for the button background */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance", meta=( sRGB="true" ))
	FLinearColor BackgroundColor;

};
