#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include"GameCamera.h"

bool Game::Start()
{
	m_spriteRender.Init("Assets/sprite/sample.dds", 1600, 900);
	m_spriteRender2.Init("Assets/sprite/sample.dds", 1600, 900);
	
	m_player = NewGO<Player>(0, "player");
	m_camera = NewGO<GameCamera>(0, "gamecamera");
	m_modelRender.Init("Assets/modelData/bg/bg.tkm");


	

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
	//m_modelRender.Draw(rc);


	
}