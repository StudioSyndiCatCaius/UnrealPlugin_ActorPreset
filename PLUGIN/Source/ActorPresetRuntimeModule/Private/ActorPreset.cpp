// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPreset.h"

void UActorPreset::ApplyModifiers(AActor* target_actor,int32 seed) const
{
	if(target_actor)
	{
		for(auto* i : Modifiers)
		{
			if(i)
			{
				i->ModifiyActor(target_actor,seed);
			}
		}
	}
}
