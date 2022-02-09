#pragma once
namespace nsK2EngineLow {
	class PostEffect
	{
	public:
		void Init();

		void Render(RenderContext& rc);
		RenderTarget offscreenRenderTarget;
	};

	extern PostEffect g_postEffect;

}
