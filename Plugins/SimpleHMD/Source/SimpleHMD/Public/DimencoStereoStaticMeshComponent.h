// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "DimencoStereoStaticMeshComponent.generated.h"

UENUM(BlueprintType)
enum class DimencoStereoPass : uint8
{
	LeftEye,
	RightEye,
	BothEyes
};

/**
 * 
 */
UCLASS(ClassGroup = (Rendering, Common), hidecategories = (Object, Activation, "Components|Activation"), ShowCategories = (Mobility), editinlinenew, meta = (BlueprintSpawnableComponent))
class SIMPLEHMD_API UDimencoStereoStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DimencoHMD")
	DimencoStereoPass EyeToRender;

	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	
	
};
