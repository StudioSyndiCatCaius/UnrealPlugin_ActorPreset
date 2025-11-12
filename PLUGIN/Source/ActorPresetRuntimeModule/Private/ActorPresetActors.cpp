// Fill out your copyright notice in the Description page of Project Settings.


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
