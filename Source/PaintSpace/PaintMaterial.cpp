// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintSpace.h"
#include "PaintMaterial.h"

// This class functions as an actor intended to hold a hierarchical instanced static mesh component.
// The actor's static mesh is set in the constructor below. Once the actor has been spawned, it can be used to add multiple instances of the static mesh.

// Sets default values
APaintMaterial::APaintMaterial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	//VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visible Component"));
	//VisibleComponent->AttachTo(RootComponent);
	//VisibleComponent->SetVisibility(true);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/Meshes/HexMesh.HexMesh'"));
	InstanceMesh = StaticMeshObject.Object;

	VisibleComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("VisibleComponent"));
	VisibleComponent->AttachTo(RootComponent);
	VisibleComponent->SetVisibility(true);

	VisibleComponent->SetStaticMesh(InstanceMesh);

	// more settings for instanced static mesh to be added

}

// Called when the game starts or when spawned
void APaintMaterial::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaintMaterial::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
}
