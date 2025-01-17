// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActorPreset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTORPRESETRUNTIMEMODULE_API UActorPreset : public UObject
{
	GENERATED_BODY()

public:
	void ApplyModifiers(AActor* target_actor) const;

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
	void ModifiyActor(AActor* Actor) const;
};
