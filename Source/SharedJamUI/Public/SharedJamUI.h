// Copyright 2016 Michael Noland. Placed under the zlib license.

#pragma once

#include "ModuleManager.h"

class FSharedJamUIModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};