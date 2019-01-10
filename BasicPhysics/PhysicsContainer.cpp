// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsContainer.h"


// Sets default values
APhysicsContainer::APhysicsContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphere = CreateDefaultSubobject<UDynamicSphere>(TEXT("sphere1"));
}

// Called when the game starts or when spawned
void APhysicsContainer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysicsContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

