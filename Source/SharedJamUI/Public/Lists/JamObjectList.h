// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

class UJamObjectTile;
class UPanelWidget;

#include "JamUserWidget.h"
#include "JamObjectList.generated.h"

UCLASS()
class SHAREDJAMUI_API UJamObjectList : public UJamUserWidget
{
	GENERATED_BODY()
	
public:	
	UJamObjectList(const FObjectInitializer& ObjectInitializer);

	// UUserWidget interface
	virtual void NativeConstruct() override;
	// End of UUserWidget interface

	// UJamUserWidget interface
	virtual void NativePreConstruct() override;
	// End of UJamUserWidget interface

	// Called to determine what kind of tile should be created for the specified object (in the case of a mixed list)
	// The default behavior is to return DefaultTileType
	UFUNCTION(BlueprintNativeEvent)
	TSubclassOf<UJamObjectTile> PickClassForObject(UObject* ObjectToVisualize);

	// This should be called after ObjectsToDisplay is mutated, before any changes will show up
	UFUNCTION(BlueprintCallable, Category="Panel")
	void RebuildObjectMap();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnListRebuilt();

public:
	// The default type of tile to display
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UJamObjectTile> DefaultTileType;
	
	// The number of empty entries to visualize in the designer (if ObjectsToDisplay is empty)
	UPROPERTY(EditAnywhere)
	int32 NumDesignerEntries;

	// The object list to display
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UObject*> ObjectsToDisplay;

	// The class list to display (appended to the ObjectsToDisplay list on construction)
	// This is sort of a hack to work around the fact that you can't assign a BP CDO to a UObject* in the editor (it actually points to the UBlueprint, which is useless)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UClass*> ClassesToDisplay;
	
	// The container to place the tiles in (e.g., horizontal or vertical box)
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UPanelWidget* TileContainer;

private:
	void AppendWidgetsInternal(TArrayView<UObject*> EffectiveList);
	void ResetContainer();
};
