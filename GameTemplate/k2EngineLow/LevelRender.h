#pragma once
#include "level3D/TklFile.h"
#include <PhysicsStaticBox.h>
#include <iterator>
#include <xutility>


namespace nsK2EngineLow {
	class MapChipRender;

	struct LevelObjectData : Noncopyable {
		Vector3 position;
		Quaternion rotation;
		Vector3 scale;
		const wchar_t* name;
		int number = 0;

		bool EqualObjectName(const wchar_t* objName)
		{
			return wcscmp(objName, name) == 0;
		}

		bool ForwardMatchName(const wchar_t* n)
		{
			auto len = wcslen(n);
			auto namelen = wcslen(name);
			if (len > namelen) {
				//���O�������B�s��v�B
				return false;
			}
			return wcsncmp(n, name, len) == 0;
		}
	};

	class PhysicsStaticBox;
	class LevelRender : public Noncopyable {
	public:
		struct BoxObjectData
		{
			Vector3 position;
			Vector3 scale;
			Quaternion rotation;
			float restitution;
		};
	private:
		using MapChipRenderPtr = std::shared_ptr<MapChipRender>;
		
	public:
		
		~LevelRender();
		/*!
		 * @brief	���x�����������B
		 *@param[in]	levelDataFilePath		tkl�t�@�C���̃t�@�C���p�X�B
		 *@param[in] hookFunc				�I�u�W�F�N�g���쐬���鎞�̏������t�b�N���邽�߂̊֐��I�u�W�F�N�g�B
		 *   �t�b�N���Ȃ��Ȃ�nullptr���w�肷��΂悢�A
		 * ���̊֐��I�u�W�F�N�g��false��Ԃ��ƁA�I�u�W�F�N�g�̏�񂩂�A
		 * �ÓI�I�u�W�F�N�g��MapChip�N���X�̃C���X�^���X����������܂��B
		 * �I�u�W�F�N�g�̖��O�ȂǂŁA�h�A��W�����v��A�A�C�e���Ȃǂ̓���ȃN���X�̃C���X�^���X�𐶐������Ƃ��ɁA
		 * �f�t�H���g�ō쐬�����MapChip�N���X�̃C���X�^���X���s�v�ȏꍇ��true��Ԃ��Ă��������B
		 * �Ⴆ�΁A�t�b�N�֐��̒��ŁA�n���ꂽ�I�u�W�F�N�g�f�[�^�̖��O�̃��f����`�悷��N���X�̃C���X�^���X��
		 * ���������Ƃ��ɁAfalse��Ԃ��Ă��܂��ƁA�������f������`�悳��邱�ƂɂȂ�܂��B
		 */
		void Init(const char* filePath, std::function<bool(LevelObjectData& objData)> hookFunc);
		/// <summary>
		/// �X�V�����B
		/// </summary>
		void Update();
		/// <summary>
		/// ���f����`��B
		/// </summary>
		/// <param name="rc">�����_�[�R���e�L�X�g�B</param>
		void Draw(RenderContext& rc);

		/// <summary>
		/// BoxCollider�𐶐�����B
		/// �����͎͂w�肵�Ȃ����0.0f�B
		/// </summary>
		/// <param name="scale">�T�C�Y�B</param>
		/// <param name="resitutation">�����́B</param>
		void InitBoxCollider(const LevelObjectData& objData,float const& restitution=0.0f);
		/// <summary>
		/// boxCollider��p������B
		/// </summary>
		void ReleaseBoxCollider();
				
		void CreateBox(const BoxObjectData* objData);
		
	private:
		/// <summary>
		/// �}�b�v�`�b�v���쐬�B
		/// </summary>
		/// <param name="objData">LevelObjectData�B</param>
		void CreateMapChipRender(const LevelObjectData& objData, const char* filePath);
		/// <summary>
		/// Tkl�t�@�C���̍s���ϊ�����B
		/// </summary>
		void MatrixTklToLevel();


	private:
		using BonePtr = std::unique_ptr<Bone>;								//�{�[��Ptr�B
		std::vector<BonePtr> m_bonelist;									//�{�[���̃��X�g�B
		std::unique_ptr<Matrix[]> m_matrixlist;								//�s��̃��X�g�B
		std::map<std::string, MapChipRenderPtr> m_mapChipRenderPtrs;		//�}�b�v�`�b�v�̉ϒ��z��B
		TklFile m_tklFile;													//Tkl�t�@�C���B
		std::unique_ptr<BoxObjectData>	m_boxobject;
		std::vector<std::unique_ptr<PhysicsStaticBox>> m_collider;

		};

}