#pragma once
class Game;
class Player;
//�Q�[�����̃J�����𐧌䂷��B
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
	/////////////////////////////////////
	//�����o�ϐ�
	/////////////////////////////////////
private:
	Player* m_Player;	//�v���C���[�B
	Vector3 m_toCameraPos;	//�����_���王�_�Ɍ������x�N�g���B
	Quaternion m_quaternion;
	Game* game;
	SpringCamera m_springCamera;
};
