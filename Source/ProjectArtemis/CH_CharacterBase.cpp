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

	IntendedDirection = FVector::ZeroVector;
	
	TargetCosmeticCameraRotation = FRotator::ZeroRotator;
	
	XRotation = 0;
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
	XRotation -= AxisValue;
	XRotation = FMath::Clamp(XRotation, -90, 90);
	View->SetRelativeRotation(FRotator(XRotation, 0, 0));
}

void ACH_CharacterBase::LookRightMouse(float AxisValue)
{
	GetController()->SetControlRotation(FRotator(0, GetController()->GetControlRotation().Yaw + AxisValue, 0));
}

void ACH_CharacterBase::UseAbility1()
{
	AbilityHolder->Ability1->UseAbility();
}

void ACH_CharacterBase::UseAbility2()
{
	AbilityHolder->Ability2->UseAbility();
}

void ACH_CharacterBase::UseAbility3()
{
	AbilityHolder->Ability3->UseAbility();
}

void ACH_CharacterBase::DoJump()
{
	Jump();
}

void ACH_CharacterBase::DoCosmeticCameraRotation(float DeltaTime)
{
	TargetCosmeticCameraRotation.Roll = FVector::DotProduct(View->GetRightVector(), GetLastMovementInputVector()) * CosmeticCameraRollMultiplier;

	//FPSCamera->SetRelativeRotation(FQuat::Slerp(FPSCamera->GetRelativeRotation().Quaternion(), TargetCosmeticCameraRotation.Quaternion(), DeltaTime * CosmeticCameraRotationLerpSpeed));
}

// Called every frame
void ACH_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DoCosmeticCameraRotation(DeltaTime);
}

// Called to bind functionality to input
void ACH_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("ForwardMovement", this, &ACH_CharacterBase::MoveForward);
	InputComponent->BindAxis("RightMovement", this, &ACH_CharacterBase::MoveRight);
	InputComponent->BindAxis("Look Up / Down Mouse", this, &ACH_CharacterBase::LookUpMouse);
	InputComponent->BindAxis("Turn Right / Left Mouse", this, &ACH_CharacterBase::LookRightMouse);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACH_CharacterBase::DoJump);
}

