// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicObject.h"
#include "DynamicPlan.generated.h"

/**
 * Dynamic plan object, by default it is static.
 */
UCLASS()
class BASICPHYSICS_API ADynamicPlan : public ADynamicObject
{
	GENERATED_BODY()
	
public:

	ADynamicPlan() : _normal(FVector::UpVector) {}
	explicit ADynamicPlan(FVector normal) : _normal(normal)
	{
		// TODO: Maybe an epsilon later on
		if (_normal == FVector::ZeroVector)
		{
			UE_LOG(LogTemp, Error, TEXT("The normal of plan can't be the zero vector!"));
			_normal = FVector::ZeroVector;
		}
		_isStatic = true;
	}

	void UpdatesForces(float deltaTime);
	
private:
	FVector _normal;
	
};
