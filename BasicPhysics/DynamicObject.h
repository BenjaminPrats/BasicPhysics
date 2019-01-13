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
	explicit ADynamicObject(float mass) : _mass(mass), _isStatic(false) {}

	//virtual ~UDynamicObject();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Updates velocity and position
	virtual void EulerIntegration(float DeltaTime);

	// Equivalent to sum of forces, acceleration
	virtual void UpdateForces() PURE_VIRTUAL(ADynamicObject::UpdateForces, ); // we don't put an extra as we want to do nothing

	// TODO: Try to find a way to put this constant in the actor and not the component (so put it in SimulationManager)
	static constexpr float cGRAVITY{ 9.81f }; // The constant gravity
	static constexpr float cAIR_RESISTANCE{ 1.0f }; // The constant gravity

protected:

	UPROPERTY()
	USceneComponent* root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;


	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	bool _isStatic = false;

	UPROPERTY(EditAnywhere)
	float _mass = 0.f;

	FVector _position{ 0.f };
	FVector _velocity{ 0.f };
	FVector _acceleration{ 0.f };

	// Moment of rotation?

	FVector _forces{ 0.f }; // Sum of forces on the gravity center of this object
	
};
