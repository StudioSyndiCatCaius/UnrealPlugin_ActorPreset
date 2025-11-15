// Caius Nelson @ Studio Syndicat - Copyright 2025. All Rights Reserved. Relased under MIT liscence.

#pragma once

#include "CoreMinimal.h"
#include "ActorPreset.h"
#include "Components/ActorComponent.h"
#include "ActorPresetComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTORPRESETRUNTIMEMODULE_API UActorPresetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorPresetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);


public:	

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorPreset")
	UActorPreset* ActorPreset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorPreset")
	int32 GenericSeed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorPreset")
	bool bAutoSeedFromPosition=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorPreset")
	bool bUpdateOnConstruction=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ActorPreset")
    bool bUpdateOnBeginPlay=true;
	
	UFUNCTION(BlueprintCallable, CallInEditor, Category="ActorPreset")
	void UpdateFromPreset();
	UFUNCTION(BlueprintCallable, CallInEditor, Category="ActorPreset")
	void SeedFromPosition();
};
