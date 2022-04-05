#pragma once

namespace nsK2EngineLow
{
	class RenderingEngine :public Noncopyable
	{
	private:
		struct ModelRenderCB
		{
			Light m_light;          // ライト
			Matrix mlvp; // ライトビュープロジェクション行列。
		};
	public:

		void Init();
		void AddRenderObject(IRenderer* renderobj)
		{
			m_renderobject.push_back(renderobj);
		}

		void Render2DDraw(RenderContext & rc);

		

		void ShadowMapDraw(RenderContext& rc);

		void Execute(RenderContext& rc);

		Texture& GetShadowMap()
		{
			return m_shadowMapRender.GetShadowMap();
		}
		Camera& GetLightCamera()
		{
			return m_shadowMapRender.GetLightCamera();
		}
		ModelRenderCB& GetModelRenderCB()
		{
			return m_modelRenderCB;
		}
	private:
		std::vector<IRenderer*> m_renderobject;
		ShadowMapRender m_shadowMapRender;
		PostEffect* m_postEffect = &g_postEffect;
		ModelRenderCB m_modelRenderCB;
		RenderTarget m_mainRenderTarget;
	
	};

	extern RenderingEngine g_renderingEngine;

}
