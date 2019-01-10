// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicObject.h"


// Sets default values for this component's properties
UDynamicObject::UDynamicObject()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDynamicObject::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDynamicObject::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDynamicObject::EulerIntegration(float deltaTime)
{
	if (_mass != 0.f)
	{
		_acceleration = _forces / _mass;
		_velocity += _acceleration * deltaTime;
		// _velocity += _forces * deltaTime / _mass;
		_position += deltaTime * _velocity;
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("The mass of this object is 0!"));
	}
}

