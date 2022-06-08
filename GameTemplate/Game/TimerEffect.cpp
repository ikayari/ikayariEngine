#include "stdafx.h"
#include "TimerEffect.h"

bool TimerEffect::Start()
{
	m_effect = NewGO<EffectEmitter>(0);
	m_effect->Init(0);
	m_effect->SetScale({ 10.0f,10.0f,10.0f });
	m_effect->Play();
	return true;
}
TimerEffect::~TimerEffect()
{

}
void TimerEffect::Update()
{

}
void TimerEffect::Render(RenderContext& rc)
{

}