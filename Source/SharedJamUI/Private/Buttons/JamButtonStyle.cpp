// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"
#include "JamButtonStyle.h"


UJamButtonStyle::UJamButtonStyle()
{
	SButton::FArguments ButtonDefaults;
	WidgetStyle = *ButtonDefaults._ButtonStyle;

	ColorAndOpacity = FLinearColor::White;
	BackgroundColor = FLinearColor::White;
}

