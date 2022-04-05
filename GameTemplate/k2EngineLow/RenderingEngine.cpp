#include "k2EngineLowPreCompile.h"
#include "RenderingEngine.h"

namespace nsK2EngineLow
{
	RenderingEngine g_renderingEngine;
	void RenderingEngine::Render2DDraw(RenderContext& rc)
	{			
		for (auto& renderObj : m_renderobject) {
			renderObj->OnRenderSprite2D(rc);
		}
		for (auto& renderObj : m_renderobject) {
			renderObj->OnRenderFont2D(rc);
		}

	}

	void RenderingEngine::ShadowMapDraw(RenderContext& rc)
	{
		m_shadowMapRender.Render(rc, g_sceneLight.GetDirectionLightDirection(), m_renderobject);
	
	}
	void RenderingEngine::Execute(RenderContext& rc)
	{
		m_modelRenderCB.m_light = g_sceneLight.GetLight();
		m_modelRenderCB.mlvp = GetLightCamera().GetProjectionMatrix();
		
		m_postEffect->Render(rc);

		Render2DDraw(rc);
		ShadowMapDraw(rc);
		
		m_renderobject.clear();
	}
	void RenderingEngine::Init()
	{
		m_postEffect = &g_postEffect;
		m_shadowMapRender.Init();
		
	}
}