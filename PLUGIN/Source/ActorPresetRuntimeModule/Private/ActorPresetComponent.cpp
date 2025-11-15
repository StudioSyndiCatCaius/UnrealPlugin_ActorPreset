// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.

#include "ActorPresetComponent.h"
#include "GameFramework/Actor.h"
#include "Helpers/PCGBlueprintHelpers.h"

// Sets default values for this component's properties
UActorPresetComponent::UActorPresetComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorPresetComponent::BeginPlay()
{
	Super::BeginPlay();
	if(bUpdateOnConstruction) { UpdateFromPreset(); }
}

void UActorPresetComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{

	FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
    
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UActorPresetComponent, ActorPreset))
	{
		//
	}
	if(bAutoSeedFromPosition) { SeedFromPosition(); }
	
	if(bUpdateOnConstruction) { UpdateFromPreset(); }
}



void UActorPresetComponent::UpdateFromPreset()
{
	if(ActorPreset && GetOwner())
	{
		ActorPreset->ApplyModifiers(GetOwner(),GenericSeed);
	}
}

void UActorPresetComponent::SeedFromPosition()
{
	GenericSeed=UPCGBlueprintHelpers::ComputeSeedFromPosition(GetOwner()->GetActorLocation());
}


