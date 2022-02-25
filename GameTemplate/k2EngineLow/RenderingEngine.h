#pragma once

namespace nsK2EngineLow
{
	class RenderingEngine :public Noncopyable
	{
	public:
        /// <summary>
		/// �`��I�u�W�F�N�g��ǉ��B
		/// </summary>
		/// <param name="renderObject"></param>
        void AddRenderObject(SpriteRender* renderObject)
        {
            m_Spriterenders.push_back(renderObject);
        }


		void SpriteRenderDraw(RenderContext& rc);


	private:
		std::vector<SpriteRender*> m_Spriterenders;

		
	};

	extern RenderingEngine g_renderingEngine;

}
