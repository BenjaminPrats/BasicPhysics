// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicSphere.h"

void ADynamicSphere::UpdateForces()
{
	_forces = FVector(0.f);

	// Gravity force
	_forces += FVector(0.f, 0.f, -cGRAVITY * _mass);

	// if collision...
	// TODO: Currently it's a test, we will need to handle the collision case here
	if (_position.Z < _radius)
	{
		_forces.Z *= -1; // opposite force
		_velocity.Z = FGenericPlatformMath::Abs(_velocity.Z); // Not like upper to not be stuck in a loop
	}
}


