// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ActorPreset.generated.h"


UCLASS(BlueprintType)
class ACTORPRESETRUNTIMEMODULE_API UActorPreset : public UObject
{
	GENERATED_BODY()

public:
	void ApplyModifiers(AActor* target_actor,int32 seed) const;

	UPROPERTY(EditAnywhere,Category="ActorPreset")
	TSubclassOf<AActor> ActorClass;
	//If this actor has an Actor Preset Component, this will automatically be set as it's preset.
	UPROPERTY(EditAnywhere,Category="ActorPreset")
	bool bAutoApplyToComponent=true;
	UPROPERTY(EditAnywhere,Instanced,Category="ActorPreset")
	TArray<UActorPresetModifier*> Modifiers;
};


UCLASS(BlueprintType,Blueprintable,Const,Abstract,EditInlineNew, meta=(ShowWorldContextPin),CollapseCategories)
class ACTORPRESETRUNTIMEMODULE_API UActorPresetModifier : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent,Category="Actor Preset Modifier")
	void ModifiyActor(AActor* Actor, int32 seed) const;
};
