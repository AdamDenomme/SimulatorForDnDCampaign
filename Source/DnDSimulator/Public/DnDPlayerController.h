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
	virtual void Tick(float DeltaSeconds) override;
protected:

	// Override SetupInputComponent to bind inputs
	virtual void SetupInputComponent() override;

	void SetInputModeGameOnly(bool InConsumeCaptureMouseDown);

	
};
