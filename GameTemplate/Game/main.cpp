#include "stdafx.h"
#include "system/system.h"
#include "Game.h"

// K2EngineLow�̃O���[�o���A�N�Z�X�|�C���g�B
K2EngineLow* g_k2EngineLow = nullptr;

/// <summary>
/// ���C���֐�
/// </summary>
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	// �Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	
	// k2EngineLow�̏������B
	g_k2EngineLow = new K2EngineLow();
	g_k2EngineLow->Init(g_hWnd, FRAME_BUFFER_W, FRAME_BUFFER_H);
	g_camera3D->SetPosition({ 0.0f, 100.0f, -200.0f });
	g_camera3D->SetTarget({ 0.0f, 50.0f, 0.0f });
	g_sceneLight.SeteyePosition(g_camera3D->GetPosition());

	NewGO<Game>(0, "game");


	g_postEffect.Init();
	g_bloom.Init();
	//step-2 �|�X�g�G�t�F�N�g���s�p�̃X�v���C�g������������B
	//�X�v���C�g�̏������I�u�W�F�N�g���쐬����B
	SpriteInitData spriteInitData;
	//�y�d�v�I�I�I�z�e�N�X�`���̓I�t�X�N���[�������_�����O���ꂽ�G�B
	spriteInitData.m_textures[0] = &g_postEffect.mainRenderTarget.GetRenderTargetTexture();
	//�y�d�v�I�I�I�z�S��ʕ`��Ȃ̂ŃX�v���C�g�̃T�C�Y�̓t���[���o�b�t�@�Ɠ����ɂ���B
	spriteInitData.m_width = 1600;
	spriteInitData.m_height = 900;
	//�y�d�v�I�I�I�z���m�N���p�̃V�F�[�_�[���w�肷��B
	spriteInitData.m_fxFilePath = "Assets/shader/monochrome.fx";
	//�������I�u�W�F�N�g���g���āA�X�v���C�g������������B
	Sprite monochromeSprite;
	monochromeSprite.Init(spriteInitData);


	
	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		auto& renderContext = g_graphicsEngine->GetRenderContext();

		// �t���[���̊J�n���ɌĂяo���K�v�����鏈�������s
		g_k2EngineLow->BeginFrame();

		// �Q�[���I�u�W�F�N�g�}�l�[�W���[�̍X�V�������Ăяo���B
		g_k2EngineLow->ExecuteUpdate();

		// �Q�[���I�u�W�F�N�g�}�l�[�W���[�̕`�揈�����Ăяo���B
		g_k2EngineLow->ExecuteRender();

		g_postEffect.Render(renderContext);
		
		//TODO �I�t�X�N���[�������_�����O�̏���
		
		//TODO sprite�̕`��B
		if (g_pad[0]->IsPress(enButtonLB1))
		{
			monochromeSprite.Draw(renderContext);
		}

		// �f�o�b�O�`�揈�������s����B
		g_k2EngineLow->DebubDrawWorld();

		// �t���[���̏I�����ɌĂяo���K�v�����鏈�������s�B
		g_k2EngineLow->EndFrame();
	}
	delete g_k2EngineLow;

	return 0;
}

