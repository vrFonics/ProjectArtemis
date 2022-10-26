// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_AbilityBase.h"
#include "Kismet/GameplayStatics.h"
#include "AC_AbilityHolder.generated.h"

struct CharacterStruct
{
	UAC_AbilityBase* Ability1;
	UAC_AbilityBase* Ability2;
	UAC_AbilityBase* Ability3;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTARTEMIS_API UAC_AbilityHolder : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_AbilityHolder();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void UpdateCharacterAbilities(CharacterStruct NewCharacterStruct);

	CharacterStruct CurrentCharacter;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<UAC_AbilityBase> Ability1Class;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UAC_AbilityBase> Ability2Class;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UAC_AbilityBase> Ability3Class;

	UPROPERTY()
	UAC_AbilityBase* Ability1;
	UPROPERTY()
	UAC_AbilityBase* Ability2;
	UPROPERTY()
	UAC_AbilityBase* Ability3;
};
