// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProceduralFloor.generated.h"

UCLASS()
class PROJECTSPITOON_API AProceduralFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralFloor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "Level")
	TArray<int> GetFloorMap();

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = "Level", meta = (AllowPrivateAccess = "true"))
	int MaxX;

	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = "Level", meta = (AllowPrivateAccess = "true"))
	int MaxY;

private:
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = "Level", meta = (AllowPrivateAccess = "true"))
	TArray<int> FloorMap;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Level", meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	FString LevelFilePath;	

	void LoadLevelFileIntoArray();
};
