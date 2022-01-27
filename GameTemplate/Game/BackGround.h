#pragma once
class BackGround : public IGameObject
{
public:
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	ModelRender m_modelRender;					//���f��
	ModelRender m_modelRender2;
	PhysicsStaticObject m_physicsStaticObject;	//�ÓI�����I�u�W�F�N�g�E
	BoxCollider m_boxCollider;

	RigidBody m_rigidBody;
};

