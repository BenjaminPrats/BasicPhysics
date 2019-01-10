// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "DynamicSphere.h"

#include "PhysicsContainer.generated.h"

UCLASS()
class BASICPHYSICS_API APhysicsContainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicsContainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UDynamicSphere* sphere;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
