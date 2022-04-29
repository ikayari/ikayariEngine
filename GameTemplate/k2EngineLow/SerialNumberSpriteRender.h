#pragma once
namespace nsK2EngineLow {
	class SerialNumberSpriteRender
	{
	public:
		/// <summary>
		/// �A�ԃA�j���[�V�����̓ǂݍ���
		/// </summary>
		/// <param name="filePath">�t�@�C���p�X�B_���O�̂��</param>
		/// <param name="w">���̒���</param>
		/// <param name="h">�c�̒���</param>
		/// <param name="n">�A�ԃA�j���[�V�����̐��B</param>
		/// <param name="alphaBlendMode">�u�����f�B���O���[�h�B</param>
		void Init(const char* filePath, const float w, const float h, const int n, AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Update();

		/// <summary>
		/// ��Z�J���[��ݒ�B
		/// </summary>
		/// <param name="mulColor">��Z�J���[�B</param>
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
		/// �s�{�b�g��ݒ�B
		/// </summary>
		/// <param name="pivot">�s�{�b�g�B</param>
		void SetPivot(const Vector2& pivot)
		{
			if (!m_isInit)
			{
				return;
			}
			m_pivot = pivot;
		}
		/// <summary>
		/// ��]��ݒ�B
		/// </summary>
		/// <param name="rot">��]�B</param>
		void SetRotation(const Quaternion& rot)
		{
			if (!m_isInit)
			{
				return;
			}
			m_rotation = rot;
		}
		/// <summary>
		/// ���W��ݒ�Bz��0.0f�ŁB
		/// </summary>
		/// <param name="pos">���W�B</param>
		void SetPosition(const Vector3& pos)
		{
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetPosition(pos);
			}
		}
	
		/// <summary>
		/// �傫����ݒ�Bz��1.0f�ŁB
		/// </summary>
		/// <param name="scale">�傫���B</param>
		void SetScale(const Vector3& scale)
		{
			int spritenumber = m_spriteRenders.size();
			for (int i = 0; i < spritenumber; i++)
			{
				m_spriteRenders[i]->SetScale(scale);
			}
		}
	

		/// <summary>
		/// �摜��`�悷�銄���B
		/// </summary>
		/// <param name="x">�`�悷�銄���B1.0f���ő�B</param>
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
		/// ���_��ݒ�B���_�����Ƃ��Ĉ����̕������摜�𐶐�����B
		/// Left 0.5���ƍ�����܊������摜���`�ʂ����B
		/// </summary>
		/// <param name="isLeft">���_�B</param>
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
		Vector3			m_position = Vector3::Zero;				//���W�B
		Quaternion		m_rotation = Quaternion::Identity;		//��]�B
		Vector3			m_scale = Vector3::One;					//�傫���B
		Vector2			m_pivot = Sprite::DEFAULT_PIVOT;		//�s�{�b�g�B
		bool m_isInit = false;
		int m_Maxnumber=0;
		float m_drawnumber=0;
	};

};