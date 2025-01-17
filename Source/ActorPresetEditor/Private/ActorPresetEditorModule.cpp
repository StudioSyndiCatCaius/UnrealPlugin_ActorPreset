// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorPresetEditorModule.h"

#include "ActorPresetFactory.h"

#define LOCTEXT_NAMESPACE "FActorPresetEditorModule"

void FActorPresetEditorModule::StartupModule()
{
	TSharedPtr<FActorPresetAssetTypeActions> AssetTypeActions_ActorPrefab = MakeShared<FActorPresetAssetTypeActions>();
	FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(AssetTypeActions_ActorPrefab.ToSharedRef());
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FActorPresetEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FActorPresetEditorModule, ActorPresetEditor)