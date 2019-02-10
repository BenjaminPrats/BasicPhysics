// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicObject.generated.h"

UCLASS()
class BASICPHYSICS_API ADynamicObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADynamicObject();
	explicit ADynamicObject(float mass) : _mass(mass), _isStatic(false)
	{
		if (mass == 0.f)
		{
			UE_LOG(LogTemp, Error, TEXT("The mass can't be zero!"));
			_mass = 1.f;
		}
	}

	//virtual ~UDynamicObject();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Updates velocity and position
	virtual void EulerIntegration(float DeltaTime);

	// Equivalent to sum of forces, acceleration
	virtual void UpdateForces(float deltaTime) PURE_VIRTUAL(ADynamicObject::UpdateForces, ); // we don't put an extra as we want to do nothing

	void SetStatic(bool isStatic) { _isStatic = isStatic; }

	ADynamicObject* _nextCollision;

	// TODO: Try to find a way to put this constant in the actor and not the component (so put it in SimulationManager)
	static constexpr float cGRAVITY{ 9.81f };		// The constant gravity
	static constexpr float cAIR_RESISTANCE{ 1.0f };	// The constant air resistance
	static constexpr float cSPACE_SCALE{ 100.0f };	// The constant of the scaling of the scene, here centimeters to meters
	static constexpr float cMITIGATION{ 0.5f };		// The constant of the mitigation by how much we decrease it
	static constexpr float EPSILON_MITIGATION{ 10.f / cSPACE_SCALE };	// Epsilon below which we will start to mitigate the position
	static constexpr float EPSILON_STOP{ 1.e-3f * EPSILON_MITIGATION };	// Epsilon below which we will start to mitigate the position

protected:
	// Changes the acceleration value
	void UpdatesAcceleration() { _acceleration = _forces / _mass; }
	// Changes the velocity value
	void UpdatesVelocity(float deltaTime) { _velocity += _acceleration * deltaTime; }
	// Changes the position value
	void UpdatesPosition(float deltaTime) { _position += _velocity * deltaTime; }
	// Returns the value of the next position without updating it
	FVector UpdatedPosition(float deltaTime);

	UPROPERTY()
	USceneComponent* root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;


	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	bool _isStatic = false;

	UPROPERTY(EditAnywhere)
	float _mass = 1.f;

	UPROPERTY(EditAnywhere)
	FVector _acceleration = FVector(0.f);

	UPROPERTY(EditAnywhere)
	FVector _velocity = FVector(0.f);

	FVector _position = FVector(0.f);

	// Moment of rotation?

	FVector _forces{ 0.f }; // Sum of forces on the gravity center of this object
	
};
