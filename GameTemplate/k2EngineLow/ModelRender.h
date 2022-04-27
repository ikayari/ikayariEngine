﻿#pragma once
#include "RenderingEngine.h"
namespace nsK2EngineLow {
	
	class ModelRender : public IRenderer
	{




	public:
		ModelRender();
		~ModelRender();

		void Update();
		/// <summary>
		/// 初期化処理。
		/// </summary>
		/// <param name="filePath">ファイルパス</param>
		/// <param name="animationClips">アニメーションクリップ</param>
		/// <param name="numAnimationClips">アニメーションの数</param>
		/// <param name="enModelUpAxis">モデルの上方向</param>
		void Init(const char* filePath,
			float recieveshadow=0.0f,
			AnimationClip* animationClips=nullptr,
			int numAnimationClips=0,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ,
			bool iscasterShadow = false);
		/// <summary>
		/// 描画処理。
		/// </summary>
		void Draw(RenderContext& rc);

		/// <summary>
		/// 座標をセット。
		/// </summary>
		/// <param name="pos">座標。</param>
		void SetPosition(const Vector3& pos)
		{
			m_position = pos;
		}
		void SetPosition(float x, float y, float z)
		{
			SetPosition({ x,y,z });
		}
		/// <summary>
		/// 回転をセット。
		/// </summary>
		/// <param name="rot">回転。</param>
		void SetRotation(const Quaternion& rot)
		{
			m_rotation = rot;
		}
		/// <summary>
		/// スケールをセット。
		/// </summary>
		/// <param name="scale">スケール。</param>
		void SetScale(const Vector3& scale)
		{
			m_scale = scale;
		}
		void SetScale(float x, float y, float z)
		{
			SetScale({ x,y,z });
		}
		/// <summary>
		/// 座標、回転、拡大率を設定。
		/// </summary>
		/// <param name="pos">座標。</param>
		/// <param name="rotation">回転。</param>
		/// <param name="scale">拡大率。</param>
		void SetTRS(const Vector3& pos, const Quaternion& rotation, const Vector3& scale)
		{
			SetPosition(pos);
			SetRotation(rotation);
			SetScale(scale);
		}
		void SetCasterShadow(const bool n)
		{
			m_isShadowCaster = n;
		}
		/// <summary>
		/// 座標を取得。
		/// </summary>
		/// <returns></returns>
		const Vector3& GetPosition() const
		{
			return m_position;
		}
		/// <summary>
		/// アニメーション再生。
		/// </summary>
		/// <param name="animNo">アニメーションクリップの番号。</param>
		/// <param name="interpolateTime">補完時間(単位：秒。)</param>
		void PlayAnimation(int animNo, float interpolateTime = 0.0f)
		{
			m_animation.Play(animNo, interpolateTime);
		}

		/// <summary>
		/// モデルを取得する。
		/// </summary>
		/// <returns>モデル</returns>
		Model& GetModel()
		{
			return m_model;
		}


	private:
		/// <summary>
		/// スケルトンの初期化。
		/// </summary>
		void InitSkeleton(const char* filePath);
		/// <summary>
		/// アニメーションの初期化。
		/// </summary>
		/// <param name="skeleton">スケルトン</param>
		/// <param name="animationClip">アニメーションクリップ</param>
		/// <param name="numAnimationClips">アニメーションの数</param>
		void InitAnimation(AnimationClip* animationClip,
			int numAnimationClips,
			EnModelUpAxis enModelUpAxis);

		void InitShadowModel(
			const char* tkmFilePath,
			EnModelUpAxis modelUpAxis);
		/// <summary>
		/// シャドウマップへの描画パスから呼ばれる処理。
		/// </summary>
		/// <param name="rc">レンダリングコンテキスト</param>
		/// <param name="ligNo">ライト番号</param>
		/// <param name="lvpMatrix">ライトビュープロジェクション行列</param>
		void OnRenderShadowMap(
			RenderContext& rc,
			Camera& camera
		)override;

		bool IsShadowCaster() const override
		{
			return m_isShadowCaster;
		}
		
		Model					m_model;								//モデル。
		Model					m_shadowmodel;							//シャドウモデル。
		Animation				m_animation;							//アニメーション。
		AnimationClip*			m_animationClip = nullptr;				//アニメーションクリップ。
		int						m_numAnimationClips = 0;				//アニメーションクリップの数。
		Skeleton				m_skeleton;								//骨。

		Vector3					m_position = Vector3::Zero;				//座標。	
		Quaternion				m_rotation = Quaternion::Identity;		//回転。
		Vector3					m_scale = Vector3::One;					//拡大率。
		EnModelUpAxis			m_enFbxUpAxis = enModelUpAxisZ;			// FBXの上方向。
		bool					m_isShadowCaster = true;

		RenderingEngine::ModelRenderCB* m_modelCB;

		

		//bool offScreenRendaring = false;
		
		
		

	};

}
