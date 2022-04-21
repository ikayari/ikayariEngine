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
		Vector3 dir = { g_sceneLight.GetDirectionLightDirection().x,g_sceneLight.GetDirectionLightDirection().y,g_sceneLight.GetDirectionLightDirection().z };
		m_shadowMapRender.Render(rc, dir, m_renderobject);


	}
	void RenderingEngine::Execute(RenderContext& rc)
	{
		m_modelRenderCB.m_light = g_sceneLight.GetLight();
		m_modelRenderCB.mlvp = GetLightCamera().GetViewProjectionMatrix();

		g_engine->ExecuteRender();
		ShadowMapDraw(rc);
		// ゲームオブジェクトマネージャーの描画処理を呼び出す。


		m_postEffect->Render(rc);
		// シャドウマップを表示するためのスプライトを初期化する
		SpriteInitData spriteInitData;
		spriteInitData.m_textures[0] = &g_renderingEngine.GetShadowMap();
		spriteInitData.m_fxFilePath = "Assets/shader/sprite.fx";
		spriteInitData.m_width = 256;
		spriteInitData.m_height = 256;

		Sprite sprite;
		sprite.Init(spriteInitData);
		sprite.Update({ FRAME_BUFFER_W / -2.0f, FRAME_BUFFER_H / 2.0f,  0.0f }, g_quatIdentity, g_vec3One, { 0.0f, 1.0f });
		sprite.Draw(rc);


		Render2DDraw(rc);

		m_renderobject.clear();
	}
	void RenderingEngine::Init()
	{
		m_postEffect = &g_postEffect;
		m_shadowMapRender.Init();
		m_modelRenderCB.m_light = g_sceneLight.GetLight();
		m_modelRenderCB.mlvp = GetLightCamera().GetViewProjectionMatrix();

	}
}