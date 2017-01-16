// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"
#include "JamObjectList.h"
#include "JamObjectTile.h"
#include "Components/PanelWidget.h"

UJamObjectList::UJamObjectList(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

TSubclassOf<UJamObjectTile> UJamObjectList::PickClassForObject_Implementation(UObject* ObjectToVisualize)
{
	return DefaultTileType;
}

void UJamObjectList::RebuildObjectMap()
{
	ResetContainer();
	AppendWidgetsInternal(MakeArrayView(ObjectsToDisplay));
	AppendWidgetsInternal(TArrayView<UObject*>((UObject**)ClassesToDisplay.GetData(), ClassesToDisplay.Num()));
	OnListRebuilt();
}

void UJamObjectList::NativeConstruct()
{
	Super::NativeConstruct();
	RebuildObjectMap();
}

void UJamObjectList::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (IsDesignTime())
	{
		if (NumDesignerEntries > 0)
		{
			TArray<UObject*> NullList;
			NullList.AddZeroed(NumDesignerEntries);

			ResetContainer();
			AppendWidgetsInternal(TArrayView<UObject*>(NullList));
			OnListRebuilt();
		}
		else
		{
			RebuildObjectMap();
		}
	}
}

void UJamObjectList::AppendWidgetsInternal(TArrayView<UObject*> EffectiveList)
{
	if (TileContainer != nullptr)
	{
		for (UObject* Object : EffectiveList)
		{
			TSubclassOf<UJamObjectTile> TileClass = PickClassForObject(Object);

			if (TileClass != nullptr)
			{
				UJamObjectTile* Tile = NewObject<UJamObjectTile>(this, TileClass);
				Tile->ParentList = this;
				Tile->MyObject = Object;

				TileContainer->AddChild(Tile);
			}
		}
	}
}

void UJamObjectList::ResetContainer()
{
	if (TileContainer != nullptr)
	{
		TileContainer->ClearChildren();
	}
}
