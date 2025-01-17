// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPresetComponent.h"

// Sets default values for this component's properties
UActorPresetComponent::UActorPresetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
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
	Super::PostEditChangeProperty(PropertyChangedEvent);
	// Get the name of the modified property
	FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
    
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UActorPresetComponent, ActorPreset))
	{
		//
	}
	
	if(bUpdateOnConstruction) { UpdateFromPreset(); }
}



void UActorPresetComponent::UpdateFromPreset()
{
	if(ActorPreset && GetOwner())
	{
		ActorPreset->ApplyModifiers(GetOwner());
	}
}


