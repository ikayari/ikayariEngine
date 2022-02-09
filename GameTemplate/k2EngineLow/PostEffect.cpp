#include "k2EngineLowPreCompile.h"
#include "PostEffect.h"

namespace nsK2EngineLow {

	PostEffect g_postEffect;

	void PostEffect::Init()
	{
		//step-1 �I�t�X�N���[���`��p�̃����_�����O�^�[�Q�b�g���쐬�B
		//RenderTarget�N���X�̃I�u�W�F�N�g���`�B
		
		//RenderTarget::Create()�𗘗p���āA�����_�����O�^�[�Q�b�g���쐬����B
		offscreenRenderTarget.Create(
			1600,												//�e�N�X�`���̕��B
			900,												//�e�N�X�`���̍����B
			1,													//Mipmap���x���B
			1,													//�e�N�X�`���z��̃T�C�Y�B
			DXGI_FORMAT_R8G8B8A8_UNORM,   //�J���[�o�b�t�@�̃t�H�[�}�b�g�B
			DXGI_FORMAT_D32_FLOAT				//�f�v�X�X�e���V���o�b�t�@�̃t�H�[�}�b�g�B
		);

	}

	void PostEffect::Render(RenderContext& rc)
	{
		// step-3 �����_�����O�^�[�Q�b�g��ύX����
		RenderTarget* rtArray[] = { &g_postEffect.offscreenRenderTarget };

		// �����_�����O�^�[�Q�b�g�Ƃ��ė��p�ł���܂ő҂�
		rc.WaitUntilToPossibleSetRenderTargets(1, rtArray);

		// �����_�����O�^�[�Q�b�g��ݒ�
		rc.SetRenderTargets(1, rtArray);

		// �����_�����O�^�[�Q�b�g���N���A
		rc.ClearRenderTargetViews(1, rtArray);

		g_engine->ExecuteRender();

		// �����_�����O�^�[�Q�b�g�ւ̏������ݏI���҂�
		rc.WaitUntilFinishDrawingToRenderTargets(1, rtArray);

		// step-5 ��ʂɕ\������郌���_�����O�^�[�Q�b�g�ɖ߂�
		rc.SetRenderTarget(
			g_graphicsEngine->GetCurrentFrameBuffuerRTV(),
			g_graphicsEngine->GetCurrentFrameBuffuerDSV()
		);
	}
}