// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"
#include "JamObjectTile.h"

UObject* UJamObjectTile::GetDefaultObjectOfMyObjectIfItIsAClass()
{
	if (UClass* MyObjectAsClass = Cast<UClass>(MyObject))
	{
		return MyObjectAsClass->GetDefaultObject<UObject>();
	}
	else
	{
		return nullptr;
	}
}
