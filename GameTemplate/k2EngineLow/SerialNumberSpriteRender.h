#pragma once
namespace nsK2EngineLow {
	class SerialNumberSpriteRender
	{
	public:
		/// <summary>
		/// 連番アニメーションの読み込み
		/// </summary>
		/// <param name="filePath">ファイルパス。_より前のやつ</param>
		/// <param name="w">横の長さ</param>
		/// <param name="h">縦の長さ</param>
		/// <param name="n">連番アニメーションの数。</param>
		/// <param name="alphaBlendMode">ブレンディングモード。</param>
		void Init(const char* filePath, const float w, const float h, const int n, AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Update();

		/// <summary>
		/// 乗算カラーを設定。
		/// </summary>
		/// <param name="mulColor">乗算カラー。</param>
		void SetMulColor(const Vector4& mulColor)
		{
			if (!m_isInit)
			{
				return;
			}
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetMulColor(mulColor);
			}
		}

		/// <summary>
		/// ピボットを設定。
		/// </summary>
		/// <param name="pivot">ピボット。</param>
		void SetPivot(const Vector2& pivot)
		{
			if (!m_isInit)
			{
				return;
			}
			m_pivot = pivot;
		}
		/// <summary>
		/// 回転を設定。
		/// </summary>
		/// <param name="rot">回転。</param>
		void SetRotation(const Quaternion& rot)
		{
			if (!m_isInit)
			{
				return;
			}
			m_rotation = rot;
		}
		/// <summary>
		/// 座標を設定。zは0.0fで。
		/// </summary>
		/// <param name="pos">座標。</param>
		void SetPosition(const Vector3& pos)
		{
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetPosition(pos);
			}
		}
	
		/// <summary>
		/// 大きさを設定。zは1.0fで。
		/// </summary>
		/// <param name="scale">大きさ。</param>
		void SetScale(const Vector3& scale)
		{
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetScale(scale);
			}
		}
	

		/// <summary>
		/// 画像を描画する割合。
		/// </summary>
		/// <param name="x">描画する割合。1.0fが最大。</param>
		void SetLimitedX(const float x)
		{
			if (!m_isInit)
			{
				return;
			}
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetLimitedX(x);
			}
			
		}
		void SetLimitedY(const float y)
		{
			if (!m_isInit)
			{
				return;
			}
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetLimitedY(y);
			}
		}

		/// <summary>
		/// 原点を設定。原点を元として引数の分だけ画像を生成する。
		/// Left 0.5だと左から五割だけ画像が描写される。
		/// </summary>
		/// <param name="isLeft">原点。</param>
		void SetIsDisplayRestrictionLeftSide(const bool isLeft)
		{
			if (!m_isInit)
			{
				return;
			}
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetIsDisplayRestrictionLeftSide(isLeft);
			}
		}
		void SetIsDisplayRestrictionRightSide(const bool isRight)
		{
			if (!m_isInit)
			{
				return;
			}
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetIsDisplayRestrictionRightSide(isRight);
			}
		}

		void SetIsDisplayRestrictionUpSide(const bool isUp)
		{
			if (!m_isInit)
			{
				return;
			}
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetIsDisplayRestrictionUpSide(isUp);
			}
		}
		void SetIsDisplayRestrictionDownSide(const bool isDown)
		{
			if (!m_isInit)
			{
				return;
			}
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetIsDisplayRestrictionDownSide(isDown);
			}
		}
		void Draw(RenderContext& rc);

		void SetDrawNumber(float n)
		{
			m_drawnumber = n;
		}
		const float& GetDrawNumber()const
		{
			return m_drawnumber;
		}
		const int& GetSpriteRendersSize()const
		{
			return m_Maxnumber;
		}
		void Release()
		{
			m_isInit = false;
			m_spriteRenders.clear();
		}

	private:
		std::vector<std::unique_ptr<SpriteRender>> m_spriteRenders;
		Vector3			m_position = Vector3::Zero;				//座標。
		Quaternion		m_rotation = Quaternion::Identity;		//回転。
		Vector3			m_scale = Vector3::One;					//大きさ。
		Vector2			m_pivot = Sprite::DEFAULT_PIVOT;		//ピボット。
		bool m_isInit = false;
		int m_Maxnumber=0;
		float m_drawnumber=0;
	};

};