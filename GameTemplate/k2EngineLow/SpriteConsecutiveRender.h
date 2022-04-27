#pragma once
namespace nsK2EngineLow
{

	class SpriteConsecutiveRender:public IRenderer
	{
	public:


		void Init(const char* filePath, const float w, const float h,const int n, AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);
		void Release()
		{
			m_sprites.clear();
		}
		void Draw(RenderContext rc);
		void Update();
	private:
		std::vector<std::unique_ptr<SpriteRender>>m_sprites;
		int m_number=0;
		bool m_isInit = false;
	};

}