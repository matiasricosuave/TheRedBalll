// Fill out your copyright notice in the Description page of Project Settings.


#include "Jugador.h"

// Sets default values
AJugador::AJugador()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> static_mesh(TEXT("StaticMesh'/Game/Cylinder.Cylinder'"));
	my_static_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMeshComponent"));
	my_static_mesh->SetStaticMesh(static_mesh.Object);
	my_static_mesh->SetWorldScale3D(FVector(0.3f, 0.3f, 0.3f));
	RootComponent = my_static_mesh;
}

// Called when the game starts or when spawned
void AJugador::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	moverse();

}



// Called to bind functionality to input
void AJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Adelante", IE_Pressed, this, &AJugador::adelante);
	PlayerInputComponent->BindAction("Adelante", IE_Released, this, &AJugador::_adelante);
	PlayerInputComponent->BindAction("Atras", IE_Pressed, this, &AJugador::atras);
	PlayerInputComponent->BindAction("Atras", IE_Released, this, &AJugador::_atras);



}


void AJugador::adelante()
{
	adel = true;
}
void AJugador::_adelante()
{
	adel = false;
}
void AJugador::atras() {
	atr = true;
}
void AJugador::_atras() {
	atr = false;
}
void AJugador::moverse()
{
	if (adel)
	{
		my_static_mesh->AddLocalOffset(FVector(10, 0, 0));
	}

	if (atr)
	{
		my_static_mesh->AddLocalOffset(FVector(-10, 0, 0));
	}
}



