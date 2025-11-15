// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FActorPresetEditorModuleModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
