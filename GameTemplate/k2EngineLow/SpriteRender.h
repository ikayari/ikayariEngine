#pragma once
namespace nsK2EngineLow {
	class SpriteRender
	{
	public:
		/// <summary>
		/// �������B
		/// </summary>
		/// <param name="filePath">�t�@�C���p�X�B</param>
		/// <param name="w">�摜�̉����B</param>
		/// <param name="h">�摜�̏c���B</param>
		/// <param name="alphaBlendMode">�f�t�H���g�͔����������B</param>
		void Init(const char* filePath, const float w, const float h, AlphaBlendMode alphaBlendMode = AlphaBlendMode_Trans);

		void Draw(RenderContext& rc);








	private:
		Sprite			m_sprite;								//�X�v���C�g�B
		Vector3			m_position = Vector3::Zero;				//���W�B
		Quaternion		m_rotation = Quaternion::Identity;		//��]�B
		Vector3			m_scale = Vector3::One;					//�傫���B
		Vector2			m_pivot = Sprite::DEFAULT_PIVOT;		//�s�{�b�g�B
	};

}
