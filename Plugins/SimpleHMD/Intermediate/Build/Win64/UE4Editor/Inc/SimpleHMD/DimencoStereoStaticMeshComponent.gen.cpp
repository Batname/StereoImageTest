// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/SimpleHMD.h"
#include "Public/DimencoStereoStaticMeshComponent.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDimencoStereoStaticMeshComponent() {}
// Cross Module References
	SIMPLEHMD_API UEnum* Z_Construct_UEnum_SimpleHMD_DimencoStereoPass();
	UPackage* Z_Construct_UPackage__Script_SimpleHMD();
	SIMPLEHMD_API UClass* Z_Construct_UClass_UDimencoStereoStaticMeshComponent_NoRegister();
	SIMPLEHMD_API UClass* Z_Construct_UClass_UDimencoStereoStaticMeshComponent();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
// End Cross Module References
static UEnum* DimencoStereoPass_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_SimpleHMD_DimencoStereoPass, Z_Construct_UPackage__Script_SimpleHMD(), TEXT("DimencoStereoPass"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_DimencoStereoPass(DimencoStereoPass_StaticEnum, TEXT("/Script/SimpleHMD"), TEXT("DimencoStereoPass"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_SimpleHMD_DimencoStereoPass()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_SimpleHMD();
		extern uint32 Get_Z_Construct_UEnum_SimpleHMD_DimencoStereoPass_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("DimencoStereoPass"), 0, Get_Z_Construct_UEnum_SimpleHMD_DimencoStereoPass_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("DimencoStereoPass"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("DimencoStereoPass::LeftEye"), 0);
			EnumNames.Emplace(TEXT("DimencoStereoPass::RightEye"), 1);
			EnumNames.Emplace(TEXT("DimencoStereoPass::BothEyes"), 2);
			EnumNames.Emplace(TEXT("DimencoStereoPass::DimencoStereoPass_MAX"), 3);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("DimencoStereoPass");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/DimencoStereoStaticMeshComponent.h"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_SimpleHMD_DimencoStereoPass_CRC() { return 1947706899U; }
	void UDimencoStereoStaticMeshComponent::StaticRegisterNativesUDimencoStereoStaticMeshComponent()
	{
	}
	UClass* Z_Construct_UClass_UDimencoStereoStaticMeshComponent_NoRegister()
	{
		return UDimencoStereoStaticMeshComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UDimencoStereoStaticMeshComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UStaticMeshComponent();
			Z_Construct_UPackage__Script_SimpleHMD();
			OuterClass = UDimencoStereoStaticMeshComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20B01080u;


				UProperty* NewProp_EyeToRender = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("EyeToRender"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(EyeToRender, UDimencoStereoStaticMeshComponent), 0x0010000000000005, Z_Construct_UEnum_SimpleHMD_DimencoStereoPass());
				UProperty* NewProp_EyeToRender_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_EyeToRender, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				static TCppClassTypeInfo<TCppClassTypeTraits<UDimencoStereoStaticMeshComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Rendering Common"));
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Object Activation Components|Activation Object Activation Components|Activation Trigger"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("DimencoStereoStaticMeshComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/DimencoStereoStaticMeshComponent.h"));
				MetaData->SetValue(NewProp_EyeToRender, TEXT("Category"), TEXT("DimencoHMD"));
				MetaData->SetValue(NewProp_EyeToRender, TEXT("ModuleRelativePath"), TEXT("Public/DimencoStereoStaticMeshComponent.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDimencoStereoStaticMeshComponent, 3707702821);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDimencoStereoStaticMeshComponent(Z_Construct_UClass_UDimencoStereoStaticMeshComponent, &UDimencoStereoStaticMeshComponent::StaticClass, TEXT("/Script/SimpleHMD"), TEXT("UDimencoStereoStaticMeshComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDimencoStereoStaticMeshComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
