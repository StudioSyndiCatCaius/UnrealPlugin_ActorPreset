// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.

#include "ActorPresetActors.h"

APreset_StaticMeshActor::APreset_StaticMeshActor()
{
	ActorPresetComponent=CreateDefaultSubobject<UActorPresetComponent>(TEXT("ActorPreset"));
}

void APreset_StaticMeshActor::OnConstruction(const FTransform& Transform)
{
	if(ActorPresetComponent)
	{
		ActorPresetComponent->UpdateFromPreset();
	}
	Super::OnConstruction(Transform);
}
