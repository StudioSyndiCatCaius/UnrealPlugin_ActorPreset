// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.
#pragma once

#include "CoreMinimal.h"
#include "ActorPreset.h"
#include "Engine/StaticMeshActor.h"
#include "ActorPresetComponent.h"
#include "ActorPresetActors.generated.h"


UCLASS()
class ACTORPRESETRUNTIMEMODULE_API APreset_StaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()

protected:
	APreset_StaticMeshActor();
	
public:	
	virtual void OnConstruction(const FTransform& Transform) override;
	
	UPROPERTY(EditAnywhere,Category="Components") UActorPresetComponent* ActorPresetComponent;
};
