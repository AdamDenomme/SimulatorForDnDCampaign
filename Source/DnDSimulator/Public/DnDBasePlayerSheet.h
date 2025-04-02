// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DnDBasePlayerSheet.generated.h"

UCLASS()
class DNDSIMULATOR_API ADnDBasePlayerSheet : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADnDBasePlayerSheet();

#pragma region Getters
	// Get unit class that represents this Hero and is used to recreate them.

	// Basic Stats
	int GetStrength() const;
	int GetDexterity() const;
	int GetConstitution() const;
	int GetIntelligence() const;
	int GetWisdom() const;
	int GetCharisma() const;

	// Dependent Stats
	int GetArmorClass() const;
	int GetHP() const;
	int GetTemporaryHP() const;
	int GetInitiative() const;
	int GetSpeed() const;
	int GetPerception() const;
	FName GetDisplayName() const;
#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

#pragma region Base Stat Block
	// Basic Stats Shared by Every DnD Unit 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Block")
	int Strength = 0;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Block")
	int Dexterity = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Block")
	int Constitution = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Block")
	int Intelligence = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Block")
	int Wisdom = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Block")
	int Charisma = 0;
#pragma endregion

#pragma region Dependent Stats
	// Other Stats Shared by Every DnD Unit
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dependent Stats")
	int ArmorClass = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dependent Stats")
	int HP = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dependent Stats")
	int TemporaryHP = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dependent Stats")
	int Initiative = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dependent Stats")
	int Speed = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Dependent Stats")
	int Perception = 0;
#pragma endregion

#pragma region Identifying Info
	// Name of the Unit
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identifying Info")
	FName DisplayName = "UnnamedHero";

	// Description of the Unit
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identifying Info")
	FText Description;
#pragma endregion

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
