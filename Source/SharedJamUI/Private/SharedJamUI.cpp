// Copyright 2016 Michael Noland. Placed under the zlib license.

#include "SharedJamUIPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FSharedJamUIModule"

void FSharedJamUIModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSharedJamUIModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSharedJamUIModule, SharedJamUI)