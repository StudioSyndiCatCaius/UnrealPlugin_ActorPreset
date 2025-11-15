// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.

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
