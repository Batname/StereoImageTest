// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../Plugins/SimpleHMD/Source/SimpleHMD/Private/SimpleHMD.h"
#include "ISimpleHMDPlugin.h"
#include "StereoImageActor.generated.h"

UCLASS()
class STEREOIMAGETEST_API AStereoImageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStereoImageActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void OnPreRenderView_RenderThread(FSceneView& InView);

	FSimpleHMD* SimpleHMD;
	
	class UMaterialInstanceDynamic* LeftDynamicMatInstance;
	class UMaterialInstanceDynamic* RightDynamicMatInstance;


	class UTexture2D* LeftTexture;
	class UTexture2D* RightTexture;

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UDimencoStereoStaticMeshComponent* LeftEyeMesh;

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UDimencoStereoStaticMeshComponent* RightEyeMesh;
};
