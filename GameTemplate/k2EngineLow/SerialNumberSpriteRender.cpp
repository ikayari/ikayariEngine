#include "k2EngineLowPreCompile.h"
#include "SerialNumberSpriteRender.h"

namespace nsK2EngineLow {
	void SerialNumberSpriteRender::Init(const char* filePath, const float w, const float h, const char* n, AlphaBlendMode alphaBlendMode)
	{
		for (int a = 0; a >int(n)-'0'; a++)
		{
			char number[] = { '0' + a };
			std::string filenumber(number);
			//スプライトレンダーの初期化。

			std::string serialFilePath = filePath;
			int pos = (int)serialFilePath.find("_");
			serialFilePath.replace(pos, int(a/10), filenumber);

			auto sprite = std::make_unique<SpriteRender>();
			sprite->Init(filePath, w, h, alphaBlendMode);
			m_spriteRenders.push_back(std::move(sprite));
		}
	}
	void SerialNumberSpriteRender::Update()
	{
		int spritenumber = m_spriteRenders.size();
		for (int i = 0; i < spritenumber; i++)
		{
			m_spriteRenders[i]->Update();
		}
	}
}