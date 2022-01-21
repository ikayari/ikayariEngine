#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include"BackGround.h"

bool Game::Start()
{
	m_player = NewGO<Player>(0, "player");
	m_backGround = NewGO<BackGround>(0, "background");
	return true;
}
void Game::Update()
{
	if (g_pad[0]->IsTrigger(enButtonStart))
	{
		Vector3 red{ 10.0f,0.0f,0.0f };
		g_directionLight.SetColor(red);
	}
}
void Game::Render(RenderContext& rc)
{

}