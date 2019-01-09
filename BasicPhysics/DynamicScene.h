// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DynamicScene.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASICPHYSICS_API UDynamicScene : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDynamicScene();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	static constexpr float GRAVITY{ 9.81f };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

		
	
};
