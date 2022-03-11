#include "k2EngineLowPreCompile.h"
#include "ShadowMapRender.h"

namespace nsK2EngineLow {



	void ShadowMapRender::Init()
	{


        // �V���h�E�}�b�v�`��p�̃����_�����O�^�[�Q�b�g���쐬����
        float clearColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        RenderTarget shadowMap;
        shadowMap.Create(
            1024,
            1024,
            1,
            1,
            DXGI_FORMAT_R8G8B8A8_UNORM,
            DXGI_FORMAT_D32_FLOAT,
            clearColor
        );
	}

    void ShadowMapRender::Render(RenderContext& rc, Vector3& ligDirection)
    {
        // �e�`��p�̃��C�g�J�������쐬����
        Camera lightCamera;
        // �J�����̈ʒu��ݒ�B����̓��C�g�̈ʒu
        lightCamera.SetPosition(0, 500, 0);

        // �J�����̒����_��ݒ�B���ꂪ���C�g���Ƃ炵�Ă���ꏊ
        lightCamera.SetTarget(0, 0, 0);

        // �������ݒ�B����̓��C�g���^���������Ă���̂ŁAX��������ɂ��Ă���
        lightCamera.SetUp(1, 0, 0);

        // ���C�g�r���[�v���W�F�N�V�����s����v�Z���Ă���
        lightCamera.Update();

        rc.WaitUntilToPossibleSetRenderTarget(shadowMap);
        rc.SetRenderTargetAndViewport(shadowMap);
        rc.ClearRenderTargetView(shadowMap);

        for (auto& model : m_Shadowmodels)
        {
            model->Draw(
                rc,
                g_matIdentity,
                lightCamera.GetProjectionMatrix()
            );
        }
        //�`�悪�I������̂ŃN���A�B
        m_Shadowmodels.clear();
        // �������݊����҂�
        rc.WaitUntilFinishDrawingToRenderTarget(shadowMap);
       

       
    }














}