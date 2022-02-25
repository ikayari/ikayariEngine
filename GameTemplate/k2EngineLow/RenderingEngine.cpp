#include "k2EngineLowPreCompile.h"
#include "RenderingEngine.h"

namespace nsK2EngineLow
{
	RenderingEngine g_renderingEngine;
	void RenderingEngine::SpriteRenderDraw(RenderContext& rc)
	{

		for (auto& renderObj : m_Spriterenders) {
			renderObj->OnRender2D(rc);
		}
		// 登録されている描画オブジェクトをクリア
		m_Spriterenders.clear();
	}

}