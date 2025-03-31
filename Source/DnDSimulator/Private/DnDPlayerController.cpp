// Fill out your copyright notice in the Description page of Project Settings.


#include "DnDPlayerController.h"

void ADnDPlayerController::BeginPlay()
{
    Super::BeginPlay();

    //SetInputModeGameOnly(true);

    // Ensure cursor is visible and events are enabled
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
}

void ADnDPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    SetInputModeGameOnly(true);
}

void ADnDPlayerController::SetInputModeGameOnly(
    bool InConsumeCaptureMouseDown)
{
    FInputModeGameOnly InputMode;
    InputMode.SetConsumeCaptureMouseDown(
        InConsumeCaptureMouseDown);
    SetInputMode(InputMode);
}