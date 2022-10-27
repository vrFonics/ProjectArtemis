// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_AbilityBase.h"
#include "Kismet/GameplayStatics.h"
#include "AC_AbilityHolder.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAC_AbilityBase> Ability1Class;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAC_AbilityBase> Ability2Class;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAC_AbilityBase> Ability3Class;
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

	void UpdateCharacterAbilities(FCharacterStruct NewCharacterStruct);
	void ChangeAbility(int AbilityIndex, TSubclassOf<UAC_AbilityBase> NewClass);

	UPROPERTY(EditAnywhere)
	FCharacterStruct CurrentCharacter;

	UPROPERTY(EditAnywhere)
	UAC_AbilityBase* Ability1;
	UPROPERTY(EditAnywhere)
	UAC_AbilityBase* Ability2;
	UPROPERTY(EditAnywhere)
	UAC_AbilityBase* Ability3;
};
