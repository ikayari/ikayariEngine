#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include"GameCamera.h"

bool Game::Start()
{
	m_spriteRender.Init("Assets/sprite/sample.dds", 1920, 1080);
	m_spriteRender2.Init("Assets/sprite/sample.dds",1920, 1080);
	
	
	

	
	//レベルを構築する。
	m_levelRender.Init("Assets/level3D/test.tkl", [&](LevelObjectData& objData) {
		//名前一致していたら。
		if (objData.EqualObjectName(L"background") == true) {


			//return falseにすると、Level側で読み込まれます。
			return false;
		}
		else if (objData.EqualObjectName(L"unityChan") == true) {

			m_player= NewGO<Player>(0, "player");
			m_player->SetTRS(objData.position, objData.rotation, objData.scale);
			return true;
		}
		return false;
		});
	m_camera = NewGO<GameCamera>(0, "gamecamera");
	


	
	
	return true;
}
void Game::Update()
{
	if (g_pad[0]->IsTrigger(enButtonStart))
	{
		Vector3 red{ 1.0f,1.0f,5.0f };
		g_sceneLight.SetAmbientLight(red);
		m_spriteRender.SetMulColor({ 0.5f, 0.5f, 0.5f, 0.5f });
	}
	if (g_pad[0]->IsTrigger(enButtonUp))
	{
		m_spriteRender.SetPosition({ 50.0f, 50.0f, 0.0f });
	}
	if (g_pad[0]->IsTrigger(enButtonDown))
	{
		m_spriteRender.SetPosition({ 100.0f, 100.0f, 0.0f });
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



	m_spriteRender.Update();




}
void Game::Render(RenderContext& rc)
{
	if(g_pad[0]->IsPress(enButtonLeft))
	m_spriteRender.Draw(rc);
	m_levelRender.Draw(rc);


	
}