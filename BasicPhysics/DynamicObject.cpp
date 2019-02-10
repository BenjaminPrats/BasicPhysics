// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicObject.h"

#include "Components/StaticMeshComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"

// Sets default values
ADynamicObject::ADynamicObject() : _mass(1.f)
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
	constexpr float deltaTime = 1.f / 25.f;
	Super::BeginPlay();
	
	// Initialization of the speed and _position
	UpdatesVelocity(deltaTime);
	_position = mesh->GetRelativeTransform().GetLocation();
	// TODO: Useless if we do it anyway in Tick after?
	UpdatesPosition(deltaTime);
	mesh->SetRelativeLocation(_position);
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

	if (_mass != 0.f) // TODO: Remove it later as it should never happen, the constructor handle it to never be 0
	{
		UpdatesAcceleration();
		UpdatesVelocity(deltaTime);
		UpdatesPosition(deltaTime);

		UE_LOG(LogTemp, Warning, TEXT("New position: %s"), *_position.ToString());

		mesh->SetRelativeLocation(_position);
		_position = mesh->GetRelativeTransform().GetLocation();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("The mass of this object is 0, should never happen!"));
	}
}

FVector ADynamicObject::UpdatedPosition(float deltaTime)
{
	// The constructor handle the case _mass = 0.f
	return FMath::Square(deltaTime) * _forces / _mass;
}