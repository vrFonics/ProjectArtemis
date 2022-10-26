// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_CharacterBase.h"

#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ACH_CharacterBase::ACH_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	View = CreateDefaultSubobject<UArrowComponent>(TEXT("ViewArrow"));
	View->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	View->AddLocalOffset(FVector(0,0,GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()/2));
	View->SetHiddenInGame(false);

	FPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	FPSCamera->AttachToComponent(View, FAttachmentTransformRules::KeepRelativeTransform);

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

