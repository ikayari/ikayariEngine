#include "k2EngineLowPreCompile.h"
#include "ShadowMapRender.h"

namespace nsK2EngineLow {



	void ShadowMapRender::Init()
	{


        // シャドウマップ描画用のレンダリングターゲットを作成する
        float clearColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        shadowMap.Create(
            1024,//【注目】レンダリングターゲットの横幅
            1024,//【注目】レンダリングターゲットの縦幅
            1,
            1,
            DXGI_FORMAT_R8G8B8A8_UNORM,
            DXGI_FORMAT_D32_FLOAT,
            clearColor
        );
	}

    void ShadowMapRender::Render(RenderContext& rc, Vector3 ligDirection, std::vector< IRenderer* >& renderObjects)
    {
        /*
        // 影描画用のライトカメラを作成する
        Camera lightCamera;
        */
        //カメラの位置を設定。これはライトの位置。
        m_lightCamera.SetPosition(0, 1500,0);
        //カメラの注視点を設定。これがライトが照らしている場所。
        m_lightCamera.SetTarget(0, 0, 0);
        //【注目】上方向を設定。今回はライトが真下を向いているので、X方向を上にしている。
        m_lightCamera.SetUp(1,0,0);
        //今回のサンプルでは画角を狭めにしておく。
        m_lightCamera.SetViewAngle(Math::DegToRad(20.0f));
        //ライトビュープロジェクション行列を計算している。
        m_lightCamera.Update();
        
        
        rc.WaitUntilToPossibleSetRenderTarget(shadowMap);
        rc.SetRenderTargetAndViewport(shadowMap);
        rc.ClearRenderTargetView(shadowMap);

        for (auto& model :renderObjects)
        {
            model->OnRenderShadowMap(rc, m_lightCamera);
        }

        rc.WaitUntilFinishDrawingToRenderTarget(shadowMap);
        // 通常レンダリング
        // レンダリングターゲットをフレームバッファに戻す
        rc.SetRenderTarget(
            g_graphicsEngine->GetCurrentFrameBuffuerRTV(),
            g_graphicsEngine->GetCurrentFrameBuffuerDSV()
        );
       rc.SetViewportAndScissor(g_graphicsEngine->GetFrameBufferViewport());
       
    }














}