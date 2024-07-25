// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (GetUnlockingActor() != nullptr) {
		UE_LOG(LogTemp, Display, TEXT("Unlocking!"));
		Mover->SetShouldMove(true);
	} else {
		UE_LOG(LogTemp, Display, TEXT("Relocking!"));
		Mover->SetShouldMove(false);
	}

}

void UTriggerComponent::SetMover(UMover* NewMover) { 
	Mover = NewMover;
}

AActor* UTriggerComponent::GetUnlockingActor() const {
	TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

	for (AActor* Actor : Actors) {
		if (Actor->ActorHasTag(UnlockTag)) {
			return Actor;
		}
	}

	return nullptr;
}