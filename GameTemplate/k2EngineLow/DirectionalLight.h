#pragma once
namespace nsK2EngineLow {


	class DirectionalLight
	{
	public:
		DirectionalLight();
		 struct DirectionLight {
			Vector3 ligDirection; //ライトの⽅向。
			//HLSL側の定数バッファのfloat3型の変数は16の倍数のアドレスに配置されるため、C++側にはパディングを埋めておく。
			float pad;
			Vector3 ligColor; //ライトのカラー。
		};

		 DirectionLight m_directionLight;
	
		DirectionLight& GetDirectionLight()
		{
			return m_directionLight;
		}
		void SetColor(const Vector3& color)
		{
			m_ligColor = color;
			m_directionLight.ligColor = m_ligColor;
		}
		void SetDirection(const Vector3& dir)
		{
			m_ligDirection = dir;
			m_ligDirection.Normalize();
			m_directionLight.ligDirection = m_ligDirection;
		}
	private:



		
		Vector3 m_ligDirection;
		Vector3 m_ligColor;
	};
	extern DirectionalLight g_directionLight;
}
