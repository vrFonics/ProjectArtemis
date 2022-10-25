// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_CharacterBase.h"

#include "Components/CapsuleComponent.h"

// Sets default values
ACH_CharacterBase::ACH_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACH_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACH_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACH_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

