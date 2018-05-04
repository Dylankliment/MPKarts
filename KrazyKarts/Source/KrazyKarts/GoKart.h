// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKARTS_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	FVector GetAirResistance();

	FVector GetRollingResistance();


	void MoveForward(float Value);

	void MoveRight(float Value);

	//Units in KG
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	UPROPERTY(EditAnywhere)
	float DragCoefficient = 16;

	UPROPERTY(EditAnywhere)
	float RollingResistanceCoefficient = 0.015;

	// The force applies to the car when throttle is fully down (N.)
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	// Num if degrees rotated per second at full control throw(cm)
	UPROPERTY(EditAnywhere)
	float MinTuringRadius = 10;

	FVector Velocity;

	float Throttle;

	float SteeringThrow;

	void UpdateLocation(float DeltaTime);

	void ApplyRotation(float DeltaTime);
};
