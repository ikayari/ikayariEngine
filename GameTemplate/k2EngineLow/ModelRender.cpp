#include "k2EngineLowPreCompile.h"
#include "ModelRender.h"

namespace nsK2EngineLow {


	ModelRender::ModelRender()
	{
		//�V�F�[�_�[�t�@�C���̃t�@�C���p�X�B������Ԃ�model.fx�B
		m_initData.m_fxFilePath = "Assets/shader/model.fx";
		//�m���X�L�����b�V���p�̒��_�V�F�[�_�[�̃G���g���[�|�C���g���w�肷��B
		m_initData.m_vsEntryPointFunc = "VSMain";
		//�X�L�����b�V���p�̒��_�V�F�[�_�[�̃G���g���[�|�C���g���w��B
		m_initData.m_vsSkinEntryPointFunc = "VSSkinMain";

	}
	ModelRender::~ModelRender()
	{

	}

	void ModelRender::Update()
	{
		//�A�j���[�V������i�߂�B
		m_animation.Progress(g_gameTime->GetFrameDeltaTime());
		m_skeleton.Update(m_model.GetWorldMatrix());
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
	}
	void ModelRender::Draw(RenderContext& rc)
	{
		m_model.Draw(rc);
	}
	void ModelRender::Init(const char* filePath,
		AnimationClip* animationClips,
		int numAnimationClips,
		EnModelUpAxis enModelUpAxis)
	{
		m_initData.m_tkmFilePath = filePath;
		InitSkeleton(filePath);
		//�X�P���g�����w�肷��B
		m_initData.m_skeleton = &m_skeleton;

		InitAnimation(animationClips, numAnimationClips, enModelUpAxis);
		m_enFbxUpAxis = enModelUpAxis;
		m_initData.m_modelUpAxis = m_enFbxUpAxis;
		m_model.Init(m_initData);

	}
	void ModelRender::Init(const char* filePath)
	{
		m_initData.m_tkmFilePath = filePath;
		m_model.Init(m_initData);
	}
	void ModelRender::InitSkeleton(const char* filePath)
	{
		//�X�P���g���̃f�[�^��ǂݍ��݁B
		std::string skeletonFilePath = filePath;
		int pos = (int)skeletonFilePath.find(".tkm");
		skeletonFilePath.replace(pos, 4, ".tks");
		m_skeleton.Init(skeletonFilePath.c_str());
	}
	void ModelRender::InitAnimation(
		AnimationClip* animationClip,
		int numAnimationClips,
		EnModelUpAxis enModelUpAxis)
	{
		m_animationClip = animationClip;
		m_numAnimationClips = numAnimationClips;
		m_animation.Init
		(	m_skeleton,
			m_animationClip,
			m_numAnimationClips
		);

	}

}