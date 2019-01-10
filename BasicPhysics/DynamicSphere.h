// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicObject.h"
#include "DynamicSphere.generated.h"

/**
 * 
 */
UCLASS()
class BASICPHYSICS_API UDynamicSphere : public UDynamicObject
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	UDynamicSphere() : _radius(0.f) { _mass = 0.f; }
	UDynamicSphere(float mass, float radius) : UDynamicObject(mass), _radius(radius) {}

	void UpdateForces();

	float _radius = 0.f;
	
	
};
