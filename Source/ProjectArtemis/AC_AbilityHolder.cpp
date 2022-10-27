// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_AbilityHolder.h"

// Sets default values for this component's properties
UAC_AbilityHolder::UAC_AbilityHolder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ..
}


// Called when the game starts
void UAC_AbilityHolder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UpdateCharacterAbilities(CurrentCharacter);
}


// Called every frame
void UAC_AbilityHolder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAC_AbilityHolder::UpdateCharacterAbilities(FCharacterStruct NewCharacterStruct)
{
	CurrentCharacter = NewCharacterStruct;
	if (NewCharacterStruct.Ability1Class != nullptr)	
	{
		ChangeAbility(0, NewCharacterStruct.Ability1Class);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Ability 1 Class is null."));
	}
	if (NewCharacterStruct.Ability2Class != nullptr)
	{
		ChangeAbility(1, NewCharacterStruct.Ability2Class);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Ability 2 Class is null."));
	}
	if (NewCharacterStruct.Ability3Class != nullptr)
	{
		ChangeAbility(2, NewCharacterStruct.Ability3Class);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Ability 3 Class is null."));
	}
}

void UAC_AbilityHolder::ChangeAbility(int AbilityIndex, TSubclassOf<UAC_AbilityBase> NewClass)
{
	switch (AbilityIndex)
	{
	case 0:
		if (IsValid(Ability1))
		{
			Ability1->DestroyComponent();
		}
		Ability1 = NewObject<UAC_AbilityBase>(GetOwner(), NewClass, TEXT("Ability 1"));
		Ability1->RegisterComponent();
		GetOwner()->AddInstanceComponent(Ability1);
		break;
	case 1:
		if (IsValid(Ability2))
		{
			Ability2->DestroyComponent();
		}
		Ability2 = NewObject<UAC_AbilityBase>(GetOwner(), NewClass, TEXT("Ability 2"));
		Ability2->RegisterComponent();
		GetOwner()->AddInstanceComponent(Ability2);
		break;
	case 2:
		if (IsValid(Ability3))
		{
			Ability3->DestroyComponent();
		}
		Ability3 = NewObject<UAC_AbilityBase>(GetOwner(), NewClass, TEXT("Ability 3"));
		Ability3->RegisterComponent();
		GetOwner()->AddInstanceComponent(Ability3);
		break;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Incorrect Index passed for ChangeAbility (must be 0, 1, or 2)"));
	}
}


