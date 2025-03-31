// Fill out your copyright notice in the Description page of Project Settings.


#include "DnDPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "../DnDSimulator.h"

void ADnDPlayerController::BeginPlay()
{
    Super::BeginPlay();

    //SetInputModeGameOnly(true);

    // Ensure cursor is visible and events are enabled
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
}

void ADnDPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    //Left Mouse Button: Drag and Drop Units
    InputComponent->BindAction("DragUnit", IE_Pressed, this, &ADnDPlayerController::SetToIsBeingDragged);
    InputComponent->BindAction("DragUnit", IE_Released, this, &ADnDPlayerController::SetToIsNotBeingDragged);
}

void ADnDPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    SetInputModeGameOnly(true);

    // Set Up Gate Logic: 
    // - Enter Every Frame
    // - Open Gate on Left Mouse Click
    // - Close Gate on Left Mouse Release

    if (IsBeingDragged)
    {
        DragObject();
        UE_LOG(LogTemp, Warning, TEXT("Input Drag: Object Picked Up!"));

    }
    else
    {
        DropObject();
        UE_LOG(LogTemp, Warning, TEXT("Input Drag: Object Dropped!"));
    }
}

void ADnDPlayerController::SetInputModeGameOnly(bool InConsumeCaptureMouseDown)
{
    FInputModeGameOnly InputMode;
    InputMode.SetConsumeCaptureMouseDown(
        InConsumeCaptureMouseDown);
    SetInputMode(InputMode);
}

void ADnDPlayerController::DragObject()
{
    // Get Player Controller
    ADnDPlayerController* PlayerController = Cast<ADnDPlayerController>(GetWorld()->GetFirstPlayerController());

    if (PlayerController)
    {
        // Get Camera from World
        APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
        FVector CameraLocation = CameraManager->GetCameraLocation();

        // Variables for MouseLocation
        FVector WorldLocation;
        FVector WorldDirection;

        // Convert Mouse Location to a 3D ray where...
        // WorldLocation: Where the Raycast starts (Cursor is Above Object)
        // WorldDirection: Direction the Ray is casted
        PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
        
        // Cast Ray 10000 Units from Raycast Position
        FVector MouseLocation = WorldLocation + (WorldDirection * 10000);

        // Define Unit Location
        FVector UnitLocation = HitActor->GetActorLocation();

        // Define Point on 3D plane where intersection will happen
        FVector PlaneNormalization = FVector(0, 0, 1.0);

        // Define new location the Unit will be moved to
        FVector NewUnitLocation; 

        // Honestly hes just a vibe dawg...
        float T = 0; 

        // This is a bool...
        bool NewUnitLocationExistence = UKismetMathLibrary::LinePlaneIntersection_OriginNormal(CameraLocation, MouseLocation, UnitLocation, PlaneNormalization, T, NewUnitLocation);

        // If true, set UnitLocation to new UnitLocation
        if (NewUnitLocationExistence)
        {
            HitActor->SetActorLocation(NewUnitLocation);
        }
        
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Input Drag: No Player Controller Found. Can not Drag Unit!"));
    }
}

void ADnDPlayerController::DropObject()
{
    if (HitActor)
    {
        HitActor = nullptr;
    }
}

void ADnDPlayerController::SetToIsBeingDragged()
{
    // Raycast Under the Cursor and Get the Hit Result
    FHitResult HitResult;
    bool BlockingHit = GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, HitResult);
    if (BlockingHit)
    {
        // Valid to Continue if it Hits a Pawn (NOT AN ACTOR)
        APawn* HitPawn = Cast<APawn>(HitResult.GetActor());

        if (IsValid(HitPawn))
        {
            HitActor = HitPawn;
            IsBeingDragged = true;
            UE_LOG(LogTemp, Log, TEXT("Hit Actor: %s"), *HitActor->GetName());
        }
    }
    else
    {
        HitActor = nullptr;
        UE_LOG(LogTemp, Warning, TEXT("Input Drag: Not Valid Hit!"));
        return;
    }
}

void ADnDPlayerController::SetToIsNotBeingDragged()
{
    IsBeingDragged = false;
}
