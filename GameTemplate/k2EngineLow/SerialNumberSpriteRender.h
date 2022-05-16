#pragma once
namespace nsK2EngineLow {
	/// <summary>
	/// �A�ԃA�j���[�V�����B
	/// �A�Ԃɂ������摜�́uunityChan_0.dds�v��A�uunityChan_10.dds�v�̂悤�Ȗ��O�ɂ��Ă��������B
	/// </summary>
	class SerialNumberSpriteRender
	{
	public:
		enum EnState
		{
			enStop,
			enPlay
		};
		/// <summary>
		/// �A�ԃA�j���[�V�����̓ǂݍ���
		/// </summary>
		/// <param name="filePath">�t�@�C���p�X�B_���O�BunityChan_0.dds���g���Ƃ���unityChan�܂ŁB</param>
		/// <param name="w">���̒���</param>
		/// <param name="h">�c�̒���</param>
		/// <param name="n">�A�ԃA�j���[�V�����̐��B</param>
		/// <param name="alphaBlendMode">�u�����f�B���O���[�h�B</param>
		void Init(const char* filePath, const float w, const float h, const int n, AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);
		/// <summary>
		/// �摜�̍X�V�@�摜�̍Đ����������˂Ă���̂ōĐ���������Ζ��t���[���Ăяo���ׂ��ł��B�i��{�c���\�j
		/// </summary>
		void Update();
		/// <summary>
		/// �Đ��J�n�B
		/// </summary>
		void Play()
		{
			m_state = enPlay;
		}
		/// <summary>
		/// �Đ���~�B
		/// </summary>
		void Stop()
		{
			m_state = enStop;
		}
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
		/// <summary>
		/// �`�揈���B
		/// </summary>
		/// <param name="rc">�����_�[�R���e�L�X�g</param>
		void Draw(RenderContext& rc);

		/// <summary>
		/// �`��摜�̏��Ԃ��Z�b�g�B
		/// </summary>
		/// <param name="n">�`�悵�����摜�̏��ԁB</param>
		void SetDrawNumber(float n)
		{
			m_drawnumber = n;
		}
		/// <summary>
		/// �`�摬�x�B
		/// </summary>
		/// <param name="speed">�w�肵�����x�{�ɍĐ�����܂��B�ʏ��1/4�t���[���Ɉ��X�V���Ǝv���܂��B</param>
		void SetDrawSpeed(int speed)
		{
			m_drawspeed = speed;
		}
		/// <summary>
		/// �`�悳��Ă�摜�����擾���܂��B
		/// </summary>
		/// <returns>���݂̕`��摜��</returns>
		const float& GetDrawNumber()const
		{
			return m_drawnumber;
		}
		/// <summary>
		/// �X�v���C�g�����_�[�̃T�C�Y���擾���܂��B
		/// </summary>
		/// <returns>�X�v���C�g�����_�[�̃T�C�Y</returns>
		const int& GetSpriteRendersSize()const
		{
			return m_Maxnumber;
		}
		/// <summary>
		/// �X�v���C�g�����_�[��j�����܂��B
		/// </summary>
		void Release()
		{
			m_isInit = false;
			m_spriteRenders.clear();
		}
		/// <summary>
		/// �`�揇��0�ɖ߂��܂�
		/// </summary>
		void DrawNumberReset()
		{
			m_drawnumber = 0;
		}
		/// <summary>
		/// ���[�v�t���O
		/// </summary>
		/// <param name="loop">true�ɂ���ƃ��[�v�B</param>
		void SetLoopFlag(bool loop)
		{
			m_isLoop=loop;
		}
	private:
		std::vector<std::unique_ptr<SpriteRender>> m_spriteRenders;
		Vector3			m_position = Vector3::Zero;				//���W�B
		Quaternion		m_rotation = Quaternion::Identity;		//��]�B
		Vector3			m_scale = Vector3::One;					//�傫���B
		Vector2			m_pivot = Sprite::DEFAULT_PIVOT;		//�s�{�b�g�B
		bool m_isInit = false;
		EnState m_state = enStop;
		int m_Maxnumber=0;
		float m_drawnumber=0;
		float m_drawratio = 0.25f;
		float m_drawspeed = 1.0f;
		bool m_isLoop = false;
		void SetState(EnState rooptype)
		{
			m_state = rooptype;
		}
		const EnState GetState()const
		{
			return m_state;
		}
	};

};