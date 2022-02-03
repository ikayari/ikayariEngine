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
private:
	// �A�j���[�V�����N���b�v�̔ԍ���\���񋓌^�B
	enum EnAnimationClip {
		enAnimClip_Idle,	// 0 : �ҋ@�A�j���[�V�����A
		enAnimClip_Run,		// 1 : ����A�j���[�V�����B
		enAnimClip_Num,		// 2 :�A�j���[�V�����N���b�v�̐��B
	};
	ModelRender m_modelRender;
	Vector3 m_position;
	Vector3 m_scale;
	Quaternion m_rotation;
	AnimationClip m_animationClipArray[enAnimClip_Num];	// �A�j���[�V�����N���b�v
	CharacterController m_charaCon;
};

