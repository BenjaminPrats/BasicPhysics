// Fill out your copyright notice in the Description page of Project Settings.

#include "SimulationManager.h"

#include "EngineUtils.h"


// Sets default values
ASimulationManager::ASimulationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimulationManager::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();

	for (TActorIterator<ADynamicObject> it(world, ADynamicObject::StaticClass()); it; ++it)
	{
		ADynamicObject* dObj = *it;
		if (dObj != NULL)
			dynamicObjects.Add(dObj);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Number of Sphere: %d"), dynamicObjects.Num());
}

// Called every frame
void ASimulationManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (auto dObj : dynamicObjects)
	{
		dObj->UpdateForces(DeltaTime);
		dObj->EulerIntegration(DeltaTime);
	}

	

}

