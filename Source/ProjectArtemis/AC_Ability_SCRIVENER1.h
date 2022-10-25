// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AC_AbilityBase.h"
#include "AC_Ability_SCRIVENER1.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTARTEMIS_API UAC_Ability_SCRIVENER1 : public UAC_AbilityBase
{
	GENERATED_BODY()
	
public:

	bool bEquipped = false;
	float MaxDistance;
	float DecalSize;
	float DelayTime;
	float Force;
	
};
