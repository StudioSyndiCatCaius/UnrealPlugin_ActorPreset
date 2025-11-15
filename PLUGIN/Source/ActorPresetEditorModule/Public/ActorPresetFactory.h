// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "ActorPreset.h"
#include "Factories/Factory.h"
#include "ActorPresetFactory.generated.h"


class FActorPresetAssetTypeActions : public FAssetTypeActions_Base
{
public:
	UClass* GetSupportedClass() const override {return UActorPreset::StaticClass();};
	FText GetName() const override { return INVTEXT("Actor Preset"); };
	FColor GetTypeColor() const override {return FColor::Cyan;};
	uint32 GetCategories() override { return EAssetTypeCategories::Misc; };
};


UCLASS()
class ACTORPRESETEDITORMODULE_API UActorPresetFactory : public UFactory
{
	GENERATED_BODY()
public:
	UActorPresetFactory();
	UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn);
};

