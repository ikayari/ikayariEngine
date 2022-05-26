#pragma once

#include <SerialNumberSpriteRender.h>
class TimerEffect : IGameObject
{
public:
	bool Start();

	void Update();

	void Render(RenderContext& renderContext);

private:
	SerialNumberSpriteRender m_Effect;
};

