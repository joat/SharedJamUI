// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"
#include "JamUIBlueprintLibrary.h"

UClass* UJamUIBlueprintLibrary::CastObjectToClass(UObject* Object)
{
	return Cast<UClass>(Object);
}

UObject* UJamUIBlueprintLibrary::GetUnsafeDefaultObjectFromClass(UClass* InClass)
{
	if (InClass != nullptr)
	{
		return InClass->GetDefaultObject<UObject>();
	}
	return nullptr;
}
