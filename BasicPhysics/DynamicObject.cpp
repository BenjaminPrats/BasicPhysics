// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicObject.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ADynamicObject::ADynamicObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	mesh->AttachTo(root);
}

// Called when the game starts or when spawned
void ADynamicObject::BeginPlay()
{
	Super::BeginPlay();
	_position = mesh->GetRelativeTransform().GetLocation();
}

// Called every frame
void ADynamicObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADynamicObject::EulerIntegration(float deltaTime)
{
	if (_isStatic)
		return;

	if (_mass != 0.f)
	{
		_acceleration = _forces / _mass;
		_velocity += _acceleration * deltaTime;
		//_velocity += _forces * deltaTime / _mass;
		_position += deltaTime * _velocity;

		UE_LOG(LogTemp, Warning, TEXT("New position: %s"), *_position.ToString());

		mesh->SetRelativeLocation(_position);
		_position = mesh->GetRelativeTransform().GetLocation();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("The mass of this object is 0!"));
	}
}