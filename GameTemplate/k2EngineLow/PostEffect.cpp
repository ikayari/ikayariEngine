#include "k2EngineLowPreCompile.h"
#include "PostEffect.h"

namespace nsK2EngineLow {

	PostEffect g_postEffect;

	void PostEffect::Init()
	{
		//step-1 オフスクリーン描画用のレンダリングターゲットを作成。
		//RenderTargetクラスのオブジェクトを定義。
		
		//RenderTarget::Create()を利用して、レンダリングターゲットを作成する。
		offscreenRenderTarget.Create(
			1600,												//テクスチャの幅。
			900,												//テクスチャの高さ。
			1,													//Mipmapレベル。
			1,													//テクスチャ配列のサイズ。
			DXGI_FORMAT_R8G8B8A8_UNORM,   //カラーバッファのフォーマット。
			DXGI_FORMAT_D32_FLOAT				//デプスステンシルバッファのフォーマット。
		);

	}

	void PostEffect::Render(RenderContext& rc)
	{
		// step-3 レンダリングターゲットを変更する
		RenderTarget* rtArray[] = { &g_postEffect.offscreenRenderTarget };

		// レンダリングターゲットとして利用できるまで待つ
		rc.WaitUntilToPossibleSetRenderTargets(1, rtArray);

		// レンダリングターゲットを設定
		rc.SetRenderTargets(1, rtArray);

		// レンダリングターゲットをクリア
		rc.ClearRenderTargetViews(1, rtArray);

		g_engine->ExecuteRender();

		// レンダリングターゲットへの書き込み終了待ち
		rc.WaitUntilFinishDrawingToRenderTargets(1, rtArray);

		// step-5 画面に表示されるレンダリングターゲットに戻す
		rc.SetRenderTarget(
			g_graphicsEngine->GetCurrentFrameBuffuerRTV(),
			g_graphicsEngine->GetCurrentFrameBuffuerDSV()
		);
	}
}