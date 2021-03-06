#pragma once
class Player:public IGameObject
{
public:
	Player() {};
	~Player() {};
	void Update();
	void Render(RenderContext& rc);

	bool Start();
	Vector3& GetPosition()
	{
		return m_position;
	}
	Quaternion& GetRotation()
	{
		return m_rotation;
	}
	void SetTRS(Vector3& pos, Quaternion& rot, Vector3& sca)
	{
		m_position = pos;
		m_rotation = rot;
		m_scale = sca;
	}
private:
	// アニメーションクリップの番号を表す列挙型。
	enum EnAnimationClip {
		enAnimClip_Idle,	// 0 : 待機アニメーション、
		enAnimClip_Run,		// 1 : 走りアニメーション。
		enAnimClip_Num,		// 2 :アニメーションクリップの数。
	};
	ModelRender m_modelRender;
	Vector3 m_position;
	Vector3 m_scale;
	Quaternion m_rotation;
	AnimationClip m_animationClipArray[enAnimClip_Num];	// アニメーションクリップ
	CharacterController m_charaCon;
};

