// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

#include "JamUserWidget.h"
#include "JamObjectTile.generated.h"

class UJamObjectList;

UCLASS(Abstract)
class SHAREDJAMUI_API UJamObjectTile : public UJamUserWidget
{
	GENERATED_BODY()
	
public:
	// The untyped object that this tile is visualizing (can be null in the designer)
	UPROPERTY(BlueprintReadOnly)
	UObject* MyObject;

	// The list that contains this tile
	UPROPERTY(BlueprintReadOnly)
	UJamObjectList* ParentList;

protected:

	UFUNCTION(BlueprintPure, Category = "User Interface")
	UObject* GetDefaultObjectOfMyObjectIfItIsAClass();
};
