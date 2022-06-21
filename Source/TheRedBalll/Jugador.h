// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Jugador.generated.h"

UCLASS(Blueprintable)
class THEREDBALLL_API AJugador : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	UStaticMeshComponent* my_static_mesh;
	AJugador();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void moverse();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void adelante();

	void _adelante();
	void atras();
	void _atras();
	bool adel;
	bool atr;

};