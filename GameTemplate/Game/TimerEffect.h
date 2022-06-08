#pragma once

class TimerEffect :public IGameObject
{
public:

	~TimerEffect();
	bool Start();

	void Update();

	void Render(RenderContext& renderContext);

	void SetPosition(const Vector3& pos)
	{
		m_position = pos;
		m_position.z = 0.0f;
	}


private:
	EffectEmitter* m_effect;
	Vector3 m_position = Vector3::Zero;
};

