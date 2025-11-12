// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPresetActorFactory.h"
#include "ActorPreset.h"
#include "ActorPresetComponent.h"

// ============================================================================================================
// ACTOR FACTORY
// ============================================================================================================


UActorPresetActorFactory::UActorPresetActorFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayName = NSLOCTEXT("ActorPreset", "PrefabActorFactoryDisplayName", "Add Prefab");
	NewActorClass = AActor::StaticClass();
	bUseSurfaceOrientation = true;
	//SpawnPositionOffset.Z=-90;
}

void UActorPresetActorFactory::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);

	if (UActorPreset* preset = Cast<UActorPreset>(Asset))
	{
		int32 in_seed=0;
		if(UActorComponent* preset_comp=NewActor->GetComponentByClass(UActorPresetComponent::StaticClass()))
		{
			Cast<UActorPresetComponent>(preset_comp)->ActorPreset=preset;
		}
		for(auto* i : preset->Modifiers)
		{
			if(i)
			{
				i->ModifiyActor(NewActor,in_seed);
			}
		}
		
	}
}

bool UActorPresetActorFactory::CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg)
{
	UE_LOG(LogTemp,Warning,TEXT("trying to create actor from prefab"));
	if (AssetData.IsValid() && AssetData.IsInstanceOf(UActorPreset::StaticClass()))
	{
		return true;
	}
	else
	{
		OutErrorMsg = NSLOCTEXT("Omega", "CanCreateActorFrom_NoSprite", "No sprite was specified.");
		return false;
	}
}

AActor* UActorPresetActorFactory::SpawnActor(UObject* InAsset, ULevel* InLevel, const FTransform& InTransform,
	const FActorSpawnParameters& InSpawnParams)
{
	if(InAsset && InAsset->GetClass()->IsChildOf(UActorPreset::StaticClass()))
	{
		UActorPreset* preset = Cast<UActorPreset>(InAsset);
		if(preset->ActorClass)
		{
			AActor* new_actor=InLevel->GetWorld()->SpawnActor<AActor>(preset->ActorClass,InTransform.GetLocation(),InTransform.Rotator());
			//FVector position;
			//FVector origin;
			//new_actor->GetActorBounds(true,origin,position,true);
			//FVector final_loc=InTransform.GetLocation();
			//final_loc.Z=position.Z/2;
			//new_actor->SetActorLocation(final_loc);
			return new_actor;
		}
	}
	return Super::SpawnActor(InAsset, InLevel, InTransform, InSpawnParams);
}

FQuat UActorPresetActorFactory::AlignObjectToSurfaceNormal(const FVector& InSurfaceNormal,
                                                           const FQuat& ActorRotation) const
{
	return FindActorAlignmentRotation(ActorRotation, FVector(0.f, 0.f, 1.f), InSurfaceNormal);
}

