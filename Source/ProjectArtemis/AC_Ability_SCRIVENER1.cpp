// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Ability_SCRIVENER1.h"

#include "EngineUtils.h"
#include "Components/DecalComponent.h"

bool UAC_Ability_SCRIVENER1::UseAbility()
{
	if (bEquipped)
	{
		bEquipped = false;
		CurrentDecal->DestroyComponent();
		CurrentDecal = nullptr;
		//Character->AbilityHolder->Weapon->Equip;
		return false;
	}
	//Character->AbilityHolder->Weapon->Unequip;
	bEquipped = true;
	UGameplayStatics::SpawnDecalAtLocation(GetWorld(),
		Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(),nullptr, TEXT("Material'/Game/DecalMaterial/MAT_SCRIVENERAbility1Decal.MAT_SCRIVENERAbility1Decal'"))),
		FVector(DecalSize, DecalSize, DecalSize),
		FVector(0,0,0),
		FRotator(0,0,0),
		0);
	return true;
}

void UAC_Ability_SCRIVENER1::BeginPlay()
{
	Super::BeginPlay();
	
}
