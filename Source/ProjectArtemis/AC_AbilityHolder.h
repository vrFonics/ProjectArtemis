// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_AbilityBase.h"
#include "AC_AbilityHolder.generated.h"


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

	UPROPERTY(EditAnywhere)
		TSubclassOf<UAC_AbilityBase> Ability1;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UAC_AbilityBase> Ability2;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UAC_AbilityBase> Ability3;
};
