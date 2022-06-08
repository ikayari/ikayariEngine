#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include"GameCamera.h"
#include "SerialNumberSpriteRender.h"
bool Game::Start()
{
	//�G�t�F�N�g��ǂݍ��ށB
	EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/ring.efk");
	EffectEngine::GetInstance()->ResistEffect(1, u"Assets/effect/laser2.efk");
	m_spriteRender.Init("Assets/sprite/flash.dds", 1600, 900);
	
	m_modelRender.SetDithering(en_pixeldithering);
	m_modelRender.Init("Assets/modelData/background.tkm");
	bgRender.SetDithering(en_dithering);
	bgRender.Init("Assets/modelData/teapot.tkm");
	bgRender.SetScale(Vector3::One * 5.0f);
	bgRender.SetPosition({ 0.0f,100.0f,500.0f });
	bgRender.Update();
	bgRender2.SetDithering(en_pixeldithering);
	bgRender2.Init("Assets/modelData/teapot.tkm");
	bgRender2.SetScale(Vector3::One * 5.0f);
	bgRender2.SetPosition({ 500.0f,100.0f,0.0f });
	bgRender2.Update();
	m_unity.Init("Assets/Sprites/Star", 1600, 900, 59);
	m_unity.Play();
	m_unity.SetDrawSpeed(4);
	m_unity.SetLoopFlag(true);
	m_player = NewGO<Player>(0, "player");
	Vector3 scale = Vector3::One * 8.0f;



	//���x�����\�z����B
	m_levelRender.Init("Assets/levelData/dithering_test.tkl", [&](LevelObjectData& objData) {
		//���O��v���Ă�����B
		if (objData.ForwardMatchName(L"LowPoly_Kon_PC") == true) {

			//return false�ɂ���ƁALevel���œǂݍ��܂�܂��B
			return false;
		}
		else if (objData.ForwardMatchName(L"Dram") == true) {

			//return false�ɂ���ƁALevel���œǂݍ��܂�܂��B

			return false;
		}
		else if (objData.ForwardMatchName(L"background") == true) {

			//return false�ɂ���ƁALevel���œǂݍ��܂�܂��B
			
			return false;
		}
		return false;
		});
	//���x�����\�z����B
	m_level2DRender.Init("Assets/sprite/test.casl", [&](Level2DObjectData& objData) {
		//���O��v���Ă�����B
		if (objData.EqualObjectName("HUD") == true) {


			//return false�ɂ���ƁALevel���œǂݍ��܂�܂��B
			return false;
		}
		else if (objData.EqualObjectName("HP") == true) {


			//return false�ɂ���ƁALevel���œǂݍ��܂�܂��B
			return false;
		}
		else if (objData.EqualObjectName("GP") == true) {


			//return false�ɂ���ƁALevel���œǂݍ��܂�܂��B
			return false;
		}
		else if (objData.EqualObjectName("unitychan") == true) {

			//���x���̃f�[�^���g�p���ĉ摜��ǂݍ��ށB
			m_spriteRender2.Init(objData.ddsFilePath, objData.width, objData.height);
			m_spriteRender2.SetScale(objData.scale);
			m_spriteRender2.SetPosition(objData.position);
			m_spriteRender2.SetPivot(objData.pivot);
			//return true�ɂ���ƁALevel2D���ŉ摜���ǂݍ��܂�܂��B
			//���g�ŉ摜��ǂݍ��݂������͕K��true�ɂ��Ă��������B
			return true;

		}
		return false;
		});
	m_camera = NewGO<GameCamera>(0, "gamecamera");

	


	box.Create({ 100.0f,100.0f,100.0f });
	
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	
	return true;
}
void Game::Update()
{


	if (g_pad[0]->IsTrigger(enButtonStart))
	{
		Vector3 red{ 1.0f,1.0f,5.0f };
		//g_sceneLight.SetAmbientLight(red);
		m_spriteRender.SetMulColor({ 0.5f, 0.5f, 0.5f, 0.5f });
		
		g_renderingEngine.SetDitheringLength(100.0f);
		m_levelRender.ReleaseBoxCollider();
		m_unity.DrawNumberReset();
		g_pad[0]->SetVibration(1.0f, 1.0f);
	}
	if (g_pad[0]->IsTrigger(enButtonUp))
	{
		m_spriteRender.SetPosition({ 50.0f, 50.0f, 0.0f });
	}
	if (g_pad[0]->IsTrigger(enButtonDown))
	{
		m_spriteRender.SetPosition({ 100.0f, 100.0f, 0.0f });
		m_unity.SetLoopFlag(false);
	}
	if (g_pad[0]->IsPress(enButtonUp))
	{
		col += {0.1f,0.1f,0.1f};
	}
	if (g_pad[0]->IsPress(enButtonDown))
	{
		col -= {0.1f, 0.1f, 0.1f};
	}

	g_sceneLight.SetDirectionColor(col);
	//A�{�^���������ꂽ��B
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		m_effect = NewGO<EffectEmitter>(0);
		m_effect->Init(0);
		m_effect->Play();

		
		//m_doorRender.PlayAnimation(enAnimClip_Open);
		m_unity.Play();

	}


	//B�{�^���������ꂽ��B
	if (g_pad[0]->IsTrigger(enButtonB))
	{
		EffectEmitter* effectEmitter = NewGO<EffectEmitter>(0);
		effectEmitter->Init(1);
		effectEmitter->SetScale({ 5.0f,5.0f,5.0f });
		effectEmitter->Play();


		m_unity.SetLoopFlag(true);

		
	}

	m_unity.Update();
	m_spriteRender.Update();
	//���x��2D���œǂݍ��񂾉摜�̍X�V�B
	m_level2DRender.Update();
	m_doorRender.Update();

	//m_pgo.CreateBox(m_player->GetPosition(), Quaternion::Identity,Vector3::One);
}
void Game::Render(RenderContext& rc)
{
	
	m_aho.Draw(rc);
	if (g_pad[0]->IsPress(enButtonA))
	{
		//m_spriteRender2.Draw(rc);
	}
	
	//m_modelRender.Draw(rc);
	//m_levelRender.Draw(rc);
	m_level2DRender.Draw(rc);
	if (g_pad[0]->IsPress(enButtonLeft))
	{
		//m_spriteRender.Draw(rc);

	}
	bgRender.Draw(rc);
	bgRender2.Draw(rc);
	//m_doorRender.Draw(rc);
	//m_unity.Draw(rc);

	
}