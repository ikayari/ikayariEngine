#pragma once
#include "SceneLight.h"
#include "ShadowMapRender.h"
#include "PostEffect.h"

namespace nsK2EngineLow
{
	struct ModelRenderCB
	{
	public:
		Light m_light;          // ���C�g
		Matrix mlvp; // ���C�g�r���[�v���W�F�N�V�����s��B
		float DitheringLength=250.0f;
	};
	class RenderingEngine :public Noncopyable
	{
	public:
		void Init();
		void AddRenderObject(IRenderer* renderobj)
		{
			m_renderobject.push_back(renderobj);
		}

		void Render2DDraw(RenderContext& rc);

		/// <summary>
		/// �f�B�U�����O�̃N���b�v�����B�f�t�H���g�ł�250.0f
		/// </summary>
		/// <param name="n">�N���b�v�����B</param>
		void SetDitheringLength(float n)
		{
			m_modelRenderCB.DitheringLength = n;
		}

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
