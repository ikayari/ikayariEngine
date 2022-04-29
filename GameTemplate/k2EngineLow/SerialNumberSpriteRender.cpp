#include "k2EngineLowPreCompile.h"
#include "SerialNumberSpriteRender.h"
#include <stdio.h>
#include <sstream>
#include <string>

namespace  nsK2EngineLow {
	void SerialNumberSpriteRender::Init(const char* filePath, const float w, const float h, const int n, AlphaBlendMode alphaBlendMode)
	{
		m_Maxnumber = n;
		for (int a = 0; a <= m_Maxnumber; a++)
		{
			std::ostringstream oss;
			//�X�v���C�g�����_�[�̏������B
			oss << filePath << '_' << a<<".dds";

			auto sprite = std::make_unique<SpriteRender>();
			sprite->Init(oss.str().c_str(), w, h, alphaBlendMode);
			m_spriteRenders.push_back(std::move(sprite));
		}
		m_isInit = true;
	}
	void SerialNumberSpriteRender::Update()
	{
		if (!m_isInit)
		{
			return;
		}
		int spritenumber = m_spriteRenders.size();
		for (int i = 0; i < spritenumber; i++)
		{
			m_spriteRenders[i]->Update();
		}
	}
	void SerialNumberSpriteRender::Draw(RenderContext& rc)
	{
		if (!m_isInit)
		{
			return;
		}
		m_spriteRenders[int(m_drawnumber)]->Draw(rc);
	}

}