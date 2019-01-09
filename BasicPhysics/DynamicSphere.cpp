// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicSphere.h"


// Sets default values
ADynamicSphere::ADynamicSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADynamicSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADynamicSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

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
