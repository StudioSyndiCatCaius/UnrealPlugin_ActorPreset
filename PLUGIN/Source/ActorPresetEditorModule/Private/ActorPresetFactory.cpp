// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.

#include "ActorPresetFactory.h"

UActorPresetFactory::UActorPresetFactory()
{
	SupportedClass = UActorPreset::StaticClass();
	bCreateNew = true;
}

UObject* UActorPresetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
                                               UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UActorPreset>(InParent, Class, Name, Flags, Context);
}
