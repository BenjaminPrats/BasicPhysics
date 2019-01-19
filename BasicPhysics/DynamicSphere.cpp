// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicSphere.h"


void ADynamicSphere::UpdateForces(float deltaTime)
{
	_forces = FVector(0.f);

	// Gravity force
	_forces += FVector(0.f, 0.f, -cGRAVITY * cSPACE_SCALE * _mass);

	// Air resistance
	_forces -= _mass * cAIR_RESISTANCE * _velocity;

	// if collision...
	// TODO: Currently it's a test, we will need to handle the collision case here
	if (_position.Z < _radius)
	{
		_forces -= FVector(0.f, 0.f, -cGRAVITY * 100.f * _mass); // Remove the last delta added to avoid "explosion"

		// To decrease and move towards the static state
		float squaredDistPosition = FVector::DistSquared(_position, UpdatedPosition(deltaTime));
		if (squaredDistPosition < EPSILON_STOP)
		{
			_forces.Z = 0.f; // opposite force with decreasing of the force
			_velocity.Z = 0.f; // Not like upper to not be stuck in a loop
		}
		else if(squaredDistPosition < EPSILON_MITIGATION)
		{
			_forces.Z *= -cMITIGATION; // opposite force with decreasing of the force
			_velocity.Z = FGenericPlatformMath::Abs(_velocity.Z * cMITIGATION); // Not like upper to not be stuck in a loop
		}
		else
		{
			_forces.Z *= -1; // opposite force
			_velocity.Z = FGenericPlatformMath::Abs(_velocity.Z); // Not like upper to not be stuck in a loop
		}
	}
	
}


