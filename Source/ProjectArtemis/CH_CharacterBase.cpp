// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_CharacterBase.h"

#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACH_CharacterBase::ACH_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	View = CreateDefaultSubobject<UArrowComponent>(TEXT("ViewArrow"));
	View->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	View->AddLocalOffset(FVector(0,0,GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()/2));

	FPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	FPSCamera->AttachToComponent(View, FAttachmentTransformRules::KeepRelativeTransform);

	AbilityHolder = CreateDefaultSubobject<UAC_AbilityHolder>(TEXT("AbilityHolder"));
}

// Called when the game starts or when spawned
void ACH_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACH_CharacterBase::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ACH_CharacterBase::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void ACH_CharacterBase::LookUpMouse(float AxisValue)
{
	View->AddLocalRotation(FRotator(-AxisValue, 0, 0));
}

void ACH_CharacterBase::LookRightMouse(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void ACH_CharacterBase::UseAbility1()
{
	
}

void ACH_CharacterBase::UseAbility2()
{
	
}

void ACH_CharacterBase::UseAbility3()
{
	
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
	InputComponent->BindAxis("ForwardMovement", this, &ACH_CharacterBase::MoveForward);
	InputComponent->BindAxis("RightMovement", this, &ACH_CharacterBase::MoveRight);
	InputComponent->BindAxis("Look Up / Down Mouse", this, &ACH_CharacterBase::LookUpMouse);
	InputComponent->BindAxis("Turn Right / Left Mouse", this, &ACH_CharacterBase::LookRightMouse);
}

