#pragma once

#include <LevelRender.h>
#include <Level2DRender.h>
#include "physics/PhysicsGhostObject.h"

#include "graphics/effect/EffectEmitter.h"
#include <SerialNumberSpriteRender.h>

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
	SerialNumberSpriteRender m_unity;

	SpriteRender m_spriteRender2;

	Vector3 col = Vector3::Zero;

	Level2DRender m_level2DRender;
	LevelRender m_levelRender;

	BoxCollider box;
	FontRender m_aho;
	RigidBody aho;
	BoxCollider bakasugi;

	PhysicsGhostObject m_pgo;

	PhysicsStaticObject m_pso;

	Sprite sprite;

	SoundSource* m_bgm = nullptr;
	ModelRender bgRender;
	ModelRender bgRender2;

	ModelRender m_doorRender;
	// �A�j���[�V�����N���b�v�̔ԍ���\���񋓌^�B
	enum EnAnimationClip {
		enAnimClip_Idle,
		enAnimClip_Open,	// 0 : �ҋ@�A�j���[�V�����A
		enAnimClip_Num,		// 1 :�A�j���[�V�����N���b�v�̐��B
	};
	AnimationClip m_animationClipArray[enAnimClip_Num];	// �A�j���[�V�����N���b�v


};

