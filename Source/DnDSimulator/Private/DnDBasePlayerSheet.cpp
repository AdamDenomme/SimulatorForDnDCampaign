// Fill out your copyright notice in the Description page of Project Settings.


#include "DnDBasePlayerSheet.h"

// Sets default values
ADnDBasePlayerSheet::ADnDBasePlayerSheet()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ADnDBasePlayerSheet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ADnDBasePlayerSheet::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

#pragma region Getters for Stat Block
// Getters for Basic Stat Block
int ADnDBasePlayerSheet::GetStrength() const
{
	return Strength;
}

int ADnDBasePlayerSheet::GetDexterity() const
{
	return Dexterity;
}

int ADnDBasePlayerSheet::GetConstitution() const
{
	return Constitution;
}

int ADnDBasePlayerSheet::GetIntelligence() const
{
	return Intelligence;
}

int ADnDBasePlayerSheet::GetWisdom() const
{
	return Wisdom;
}

int ADnDBasePlayerSheet::GetCharisma() const
{
	return Charisma;
}
#pragma endregion

#pragma region Getters for Dependent Stats
// Getters for Dependent Stats
int ADnDBasePlayerSheet::GetArmorClass() const
{
	return ArmorClass;
}

int ADnDBasePlayerSheet::GetHP() const
{
	return HP;
}

int ADnDBasePlayerSheet::GetTemporaryHP() const
{
	return TemporaryHP;
}

int ADnDBasePlayerSheet::GetInitiative() const
{
	return Initiative;
}

int ADnDBasePlayerSheet::GetSpeed() const
{
	return Speed;
}

int ADnDBasePlayerSheet::GetPerception() const
{
	return Perception;
}

FName ADnDBasePlayerSheet::GetDisplayName() const
{
	return DisplayName;
}
#pragma endregion


