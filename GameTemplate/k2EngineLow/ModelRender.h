#pragma once
namespace nsK2EngineLow {

	class ModelRender 
	{
	public:
		ModelRender();
		~ModelRender();

		void Update();
		/// <summary>
		/// �����������B
		/// </summary>
		/// <param name="filePath">�t�@�C���p�X</param>
		/// <param name="animationClips">�A�j���[�V�����N���b�v</param>
		/// <param name="numAnimationClips">�A�j���[�V�����̐�</param>
		/// <param name="enModelUpAxis">���f���̏����</param>
		void Init(const char* filePath,
			AnimationClip* animationClips,
			int numAnimationClips,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ);
		/// <summary>
		/// �����������B
		/// </summary>
		/// <param name="filePath">�t�@�C���p�X</param>
		void Init(const char* filePath);
		/// <summary>
		/// �`�揈���B
		/// </summary>
		void Draw(RenderContext& rc);

		/// <summary>
		/// ���W���Z�b�g�B
		/// </summary>
		/// <param name="pos">���W�B</param>
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}
		void SetPosition(float x,float y,float z)
		{
			SetPosition({ x,y,z });
		}
		/// <summary>
		/// ��]���Z�b�g�B
		/// </summary>
		/// <param name="rot">��]�B</param>
		void SetRotation(const Quaternion& rot)
		{
			m_rotation = rot;
		}
		/// <summary>
		/// �X�P�[�����Z�b�g�B
		/// </summary>
		/// <param name="scale">�X�P�[���B</param>
		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}
		void SetScale(float x, float y, float z)
		{
			SetScale({ x,y,z });
		}
		
		/// <summary>
		/// �A�j���[�V�����Đ��B
		/// </summary>
		/// <param name="animNo">�A�j���[�V�����N���b�v�̔ԍ��B</param>
		/// <param name="interpolateTime">�⊮����(�P�ʁF�b�B)</param>
		void PlayAnimation(int animNo, float interpolateTime = 0.0f)
		{
			m_animation.Play(animNo, interpolateTime);
		}

		/// <summary>
		/// ���f�����擾����B
		/// </summary>
		/// <returns>���f��</returns>
		Model& GetModel() 
		{
			return m_model;
		}


	private:
		/// <summary>
		/// �X�P���g���̏������B
		/// </summary>
		void InitSkeleton(const char* filePath);
		/// <summary>
		/// �A�j���[�V�����̏������B
		/// </summary>
		/// <param name="skeleton">�X�P���g��</param>
		/// <param name="animationClip">�A�j���[�V�����N���b�v</param>
		/// <param name="numAnimationClips">�A�j���[�V�����̐�</param>
		void InitAnimation(AnimationClip* animationClip,
			int numAnimationClips,
			EnModelUpAxis enModelUpAxis);
		Model					m_model;								//���f���B
		ModelInitData			m_initData;								//�������f�[�^�B
		Animation				m_animation;							//�A�j���[�V�����B
		AnimationClip*			m_animationClip = nullptr;				//�A�j���[�V�����N���b�v�B
		int						m_numAnimationClips = 0;				//�A�j���[�V�����N���b�v�̐��B
		Skeleton				m_skeleton;								//���B

		Vector3					m_position=Vector3::Zero;				//���W�B	
		Quaternion				m_rotation=Quaternion::Identity;		//��]�B
		Vector3					m_scale=Vector3::One;					//�g�嗦�B
		EnModelUpAxis			m_enFbxUpAxis = enModelUpAxisZ;		// FBX�̏�����B
	};

}