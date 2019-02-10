// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DynamicObject.h"

/**
 * Data structure which kept the information of a collision between two ADynamicObjects
 */
class BASICPHYSICS_API DynamicCollision
{
public:
	DynamicCollision() : _ptrCollidedObj(nullptr), _normal(FVector::UpVector), _position(FVector::ZeroVector) {}
	DynamicCollision(ADynamicObject* ptrCollidedObj, const FVector& normal, const FVector& position) : 
		_ptrCollidedObj(ptrCollidedObj), _normal(normal), _position(position) {}
	~DynamicCollision();

	ADynamicObject* _ptrCollidedObj;
	FVector _normal;					// Normal of the surface of the collision in 
	FVector _position;					// Position of the collision

};
