// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectSpitoon.h"
#include "ProceduralFloor.h"

// Sets default values
AProceduralFloor::AProceduralFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;	
}

// Called when the game starts or when spawned
void AProceduralFloor::BeginPlay()
{
	LoadLevelFileIntoArray();
	Super::BeginPlay();
}

// Called every frame
void AProceduralFloor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AProceduralFloor::LoadLevelFileIntoArray() {
	FString Result;	
	LevelFilePath = FPaths::GameDir()+"Content/"+ LevelFilePath;
	UE_LOG(LogTemp, Warning, TEXT("File path is %s "), *LevelFilePath);
	FFileHelper::LoadFileToString(Result, *LevelFilePath, 0);	
	if (!Result.IsEmpty()) {
		for (int index = 0; index < Result.Len(); index++) {
			if (Result[index] == '\n') {				
				MaxX++;
			}
			else {
				if (Result[index] != 13) {
					UE_LOG(LogTemp, Warning, TEXT("Result value values are %d "), Result[index]);
					FloorMap.Add(Result[index] - '0');
				}
			}
		}
	}
	MaxX++;
	MaxY = FloorMap.Num() / MaxX;
	UE_LOG(LogTemp, Warning, TEXT("MaxX and MaxY values are %d %d "),MaxX,MaxY);
}

TArray<int> AProceduralFloor::GetFloorMap() {
	return FloorMap;
}

void AProceduralFloor::DestroyLevel() {
	Destroy();
}