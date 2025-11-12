// Fill out your copyright notice in the Description page of Project Settings.


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
