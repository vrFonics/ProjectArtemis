// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AC_AbilityHolder.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "CH_CharacterBase.generated.h"

UCLASS()
class PROJECTARTEMIS_API ACH_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACH_CharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	void LookUpMouse(float AxisValue);
	void LookRightMouse(float AxisValue);

	void UseAbility1();
	void UseAbility2();
	void UseAbility3();

	void DoJump();

	void DoCosmeticCameraRotation(float DeltaTime);

	UPROPERTY()
	UArrowComponent* View;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* FPSCamera;

	UPROPERTY()
	FVector IntendedDirection;

	UPROPERTY()
	FRotator TargetCosmeticCameraRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CosmeticCameraRollMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CosmeticCameraRotationLerpSpeed;

	float XRotation;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float ViewRotation;
	float StartingHealth;
	float CurrentHealth;
	float LookSensitivity;

	UPROPERTY(EditAnywhere)
	UAC_AbilityHolder* AbilityHolder;
};
