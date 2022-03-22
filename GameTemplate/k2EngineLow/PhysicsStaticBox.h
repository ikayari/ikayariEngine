#pragma once

#include "physics/RigidBody.h"

#include <LevelRender.h>
#include <iterator>




namespace nsK2EngineLow {
	class LevelObjectData;



	class PhysicsStaticBox
	{
	public:

		
		PhysicsStaticBox();
		~PhysicsStaticBox() {};

		void Create(const nsK2EngineLow::LevelRender::BoxObjectData* objData);


		
	private:
		BoxCollider	m_boxCollider;				//�{�b�N�X�R���C�_�[
		RigidBody	m_rigidBody;				//���́B
		
	};

}
