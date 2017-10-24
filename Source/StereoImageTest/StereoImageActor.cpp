// Fill out your copyright notice in the Description page of Project Settings.

#include "StereoImageActor.h"
#include "DimencoStereoStaticMeshComponent.h"

#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"

// Sets default values
AStereoImageActor::AStereoImageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Just make root component
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
		FConstructorStatics()
			: PlaneMesh(TEXT("StaticMesh'/Game/ThirdPersonCPP/Blueprints/SM_DemoPlate.SM_DemoPlate'"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create Left static mesh component
	LeftEyeMesh = CreateDefaultSubobject<UDimencoStereoStaticMeshComponent>(TEXT("LeftEyeMesh"));
	LeftEyeMesh->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());	// Set static mesh
	LeftEyeMesh->EyeToRender = DimencoStereoPass::LeftEye;
	LeftEyeMesh->SetupAttachment(RootComponent);

	// Create Right static mesh component
	RightEyeMesh = CreateDefaultSubobject<UDimencoStereoStaticMeshComponent>(TEXT("RightEyeMesh"));
	RightEyeMesh->SetStaticMesh(ConstructorStatics.PlaneMesh.Get());	// Set static mesh
	RightEyeMesh->EyeToRender = DimencoStereoPass::RightEye;
	RightEyeMesh->SetupAttachment(RootComponent);

	// Set Left Material
	static ConstructorHelpers::FObjectFinder<UMaterial> LeftMat(TEXT("Material'/Game/ThirdPersonCPP/Blueprints/LeftMat.LeftMat'"));
	if (LeftMat.Succeeded())
	{
		LeftEyeMesh->SetMaterial(0, LeftMat.Object);
	}

	// Set Right  Material
	static ConstructorHelpers::FObjectFinder<UMaterial> RightMat(TEXT("Material'/Game/ThirdPersonCPP/Blueprints/RightMat.RightMat'"));
	if (RightMat.Succeeded())
	{
		RightEyeMesh->SetMaterial(0, RightMat.Object);
	}

	// FindTextures
	static ConstructorHelpers::FObjectFinder<UTexture2D> LTex(TEXT("Texture2D'/Game/ThirdPersonCPP/Blueprints/L.L'"));
	if (LTex.Succeeded())
	{
		LeftTexture = LTex.Object;
	}

	static ConstructorHelpers::FObjectFinder<UTexture2D> RTex(TEXT("Texture2D'/Game/ThirdPersonCPP/Blueprints/R.R'"));
	if (RTex.Succeeded())
	{
		RightTexture = RTex.Object;
	}

}

// Called every frame
void AStereoImageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStereoImageActor::BeginPlay()
{
	Super::BeginPlay();

	SimpleHMD = ISimpleHMDPlugin::Get().GetHDMRef();

	UE_LOG(LogTemp, Warning, TEXT("AStereoImageActor SimpleHMD %p"), SimpleHMD);
	if (SimpleHMD)
	{
		SimpleHMD->PreRenderView_RenderThread_Delegate.AddUObject(this, &AStereoImageActor::OnPreRenderView_RenderThread);
	}

	// Create dynamic mat instance
	LeftDynamicMatInstance = LeftEyeMesh->CreateAndSetMaterialInstanceDynamic(0);
	RightDynamicMatInstance = RightEyeMesh->CreateAndSetMaterialInstanceDynamic(0);

}

void AStereoImageActor::OnPreRenderView_RenderThread(FSceneView& InView)
{
	//if (InView.StereoPass == EStereoscopicPass::eSSP_LEFT_EYE)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AStereoImageActor OnPreRenderView_RenderThread eSSP_LEFT_EYE"));
	//	if (DynamicMatInstance)
	//	{
	//		if (LeftTexture)
	//		{
	//			DynamicMatInstance->SetTextureParameterValue(FName("ImageTexture"), LeftTexture);
	//		}
	//	}
	//}
	//if (InView.StereoPass == EStereoscopicPass::eSSP_RIGHT_EYE)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("AStereoImageActor OnPreRenderView_RenderThread eSSP_RIGHT_EYE"));
	//	if (DynamicMatInstance)
	//	{
	//		if (RightTexture)
	//		{
	//			DynamicMatInstance->SetTextureParameterValue(FName("ImageTexture"), RightTexture);

	//		}
	//	}
	//}

}


