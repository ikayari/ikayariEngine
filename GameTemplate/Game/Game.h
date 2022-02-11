#pragma once

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

	Vector3 col = Vector3::Zero;
};

