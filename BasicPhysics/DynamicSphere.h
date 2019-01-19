// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicObject.h"
#include "DynamicSphere.generated.h"

/**
 * 
 */
UCLASS()
class BASICPHYSICS_API ADynamicSphere : public ADynamicObject
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ADynamicSphere() : _radius(0.f) { _mass = 0.f; }
	ADynamicSphere(float mass, float radius) : ADynamicObject(mass), _radius(radius) {}

	void UpdateForces(float deltaTime);

	float _radius = 0.f;
	
	
};
