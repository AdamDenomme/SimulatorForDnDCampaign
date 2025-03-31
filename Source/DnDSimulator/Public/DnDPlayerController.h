// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DnDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DNDSIMULATOR_API ADnDPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	//Used to Update Location of Dragged Object/Fix Double Click
	virtual void Tick(float DeltaSeconds) override;

	AActor* HitActor;

protected:
	// Override SetupInputComponent to bind inputs
	virtual void SetupInputComponent() override;
	void SetInputModeGameOnly(bool InConsumeCaptureMouseDown);

private:

	// Drag and Drop Units Functionality
	UFUNCTION()
	void DragObject();

	UFUNCTION()
	void DropObject();

	// Drag and Drop Units Gate Logic
	UFUNCTION()
	void SetToIsBeingDragged();

	UFUNCTION()
	void SetToIsNotBeingDragged();

	bool IsBeingDragged;

	
};
