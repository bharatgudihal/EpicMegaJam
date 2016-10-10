// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Floor.generated.h"

UCLASS()
class PROJECTSPITOON_API AFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return FloorMesh; }

	UFUNCTION(BlueprintPure, Category = "Floor")
	FORCEINLINE FVector GetBaseVector() const { return BaseVector; }

private:
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Floor", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* FloorMesh;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Floor", meta = (AllowPrivateAccess = "true"))
	FVector BaseVector;
	
};
