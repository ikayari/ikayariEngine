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
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();
	Vector3 moveSpeed;
	//カメラの前方向と右方向のベクトルを持ってくる。
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y方向には移動させない。
	forward.y = 0.0f;
	right.y = 0.0f;

	forward.Normalize();
	right.Normalize();
	//左スティックの入力量と120.0fを乗算。
	right *= stickL.x * 120.0f;
	forward *= stickL.y * 120.0f;

	//移動速度に上記で計算したベクトルを加算する。
	moveSpeed += right + forward;
	m_position=m_charaCon.Execute(moveSpeed, g_gameTime->GetFrameDeltaTime());
	//m_modelRender.SetPosition(m_position);
	m_modelRender.Update();
	Vector3 pos = m_position;
	pos.y += 50.0f;
	g_sceneLight.SetPointLightPosition(pos);

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