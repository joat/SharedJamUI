// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "JamUIBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SHAREDJAMUI_API UJamUIBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "User Interface")
	static UClass* CastObjectToClass(UObject* Object);

	UFUNCTION(BlueprintPure, Category = "User Interface")
	static UObject* GetUnsafeDefaultObjectFromClass(UClass* Class);
};
