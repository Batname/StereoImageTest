// Fill out your copyright notice in the Description page of Project Settings.

#include "SimpleHMD.h"
#include "DimencoStereoStaticMeshComponent.h"
#include "StaticMeshResources.h"
#include "Engine/StaticMesh.h"



class FDimencoStereoStaticMeshSceneProxy
	: public FStaticMeshSceneProxy
{
	DimencoStereoPass EyeToRender;

public:

	FDimencoStereoStaticMeshSceneProxy(UDimencoStereoStaticMeshComponent* Component) :
		FStaticMeshSceneProxy(Component, false)
	{
		EyeToRender = Component->EyeToRender;
	}

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		FPrimitiveViewRelevance viewRelevance = FStaticMeshSceneProxy::GetViewRelevance(View);
		bool bVisible = true;

		switch (View->StereoPass)
		{
		case eSSP_RIGHT_EYE:
			if ((EyeToRender != DimencoStereoPass::RightEye) && (EyeToRender != DimencoStereoPass::BothEyes))
			{
				bVisible = false;
			}
			break;

		case eSSP_LEFT_EYE:
			if ((EyeToRender != DimencoStereoPass::LeftEye) && (EyeToRender != DimencoStereoPass::BothEyes))
			{
				bVisible = false;
			}
			break;

		case eSSP_FULL:
		default:
			//Draw both planes when in mono mode
			break;
		}

		viewRelevance.bDrawRelevance &= bVisible;

		return viewRelevance;

	}
};


FPrimitiveSceneProxy* UDimencoStereoStaticMeshComponent::CreateSceneProxy()
{
	if ((GetStaticMesh() == nullptr) ||
		(GetStaticMesh()->RenderData == nullptr) ||
		(GetStaticMesh()->RenderData->LODResources.Num() == 0) ||
		(GetStaticMesh()->RenderData->LODResources[0].VertexBuffer.GetNumVertices() == 0))
	{
		return nullptr;
	}

	FPrimitiveSceneProxy* Proxy = ::new FDimencoStereoStaticMeshSceneProxy(this);

	return Proxy;
}
