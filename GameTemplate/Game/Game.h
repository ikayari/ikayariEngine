#pragma once

#include <LevelRender.h>
#include <Level2DRender.h>

class Player;
class GameCamera;
class Game : public IGameObject
{
public:

	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	Player* m_player = nullptr;
	GameCamera* m_camera = nullptr;

	ModelRender m_modelRender;
	SpriteRender m_spriteRender;

	SpriteRender m_spriteRender2;

	Vector3 col = Vector3::Zero;

	Level2DRender m_level2DRender;
	LevelRender m_levelRender;
};

