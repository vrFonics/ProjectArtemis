// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_AbilityBase.h"

// Sets default values for this component's properties
UAC_AbilityBase::UAC_AbilityBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_AbilityBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CurrentCooldownTime = 0;
}


// Called every frame
void UAC_AbilityBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (!(CurrentCooldownTime <= 0)) {
		CurrentCooldownTime -= DeltaTime;
	}
}

bool UAC_AbilityBase::UseAbility()
{
	if (CurrentCooldownTime <= 0) {
		CurrentCooldownTime = Cooldown;
		return true;
	}
	return false;
}

