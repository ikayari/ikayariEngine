#include "stdafx.h"
#include "Player.h"

bool Player::Start()
{
	//アニメーションクリップをロードする。
	m_animationClipArray[enAnimClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClipArray[enAnimClip_Idle].SetLoopFlag(true);
	m_animationClipArray[enAnimClip_Run].Load("Assets/animData/walk.tka");
	m_animationClipArray[enAnimClip_Run].SetLoopFlag(true);
	//tkmファイルのファイルパスを指定する。
	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClipArray, enAnimClip_Num, enModelUpAxisY);
	m_charaCon.Init(25.0f, 75.0f, m_position);
	return true;
}

void Player::Update()
{
	
	if (g_pad[0]->IsTrigger(enButtonB))
	{
		m_modelRender.PlayAnimation(enAnimClip_Run, 0.1f);
	}
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		m_modelRender.PlayAnimation(enAnimClip_Idle, 0.1f);
	}
	if (g_pad[0]->IsPress(enButtonY))
	{
		m_rotation.AddRotationDegY(5.0f);
		m_modelRender.SetRotation(m_rotation);
	}
	Vector3 moveSpeed;
	moveSpeed.x = g_pad[0]->GetLStickXF() * 120.0f;
	moveSpeed.z = g_pad[0]->GetLStickYF() * 120.0f;
	m_position=m_charaCon.Execute(moveSpeed, g_gameTime->GetFrameDeltaTime());
	//m_modelRender.SetPosition(m_position);
	m_modelRender.Update();
	g_sceneLight.SetPointLightPosition(m_position);

	// step-4 コントローラー右スティックでスポットライトを回転させる
		// Y軸周りの回転クォータニオンを計算する
	Quaternion qRotY;
	qRotY.SetRotationY(g_pad[0]->GetRStickXF() * 0.01f);

	// 計算したクォータニオンでライトの方向を回す
	g_sceneLight.ApplySpotLightRotation(qRotY);

	// X軸周りの回転クォータニオンを計算する
	Vector3 rotAxis;
	rotAxis.Cross(g_vec3AxisY,g_sceneLight.GetSpotLightDirection());
	Quaternion qRotX;
	qRotX.SetRotation(rotAxis, g_pad[0]->GetRStickYF() * -0.01f);

	// 計算したクォータニオンでライトの方向を回す
	g_sceneLight.ApplySpotLightRotation(qRotX);

}

void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}