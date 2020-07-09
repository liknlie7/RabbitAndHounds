#include "pch.h"
#include "GameObject.h"

// �R���X�g���N�^
GameObject::GameObject()
	: m_position(0.0f, 0.0f, 0.0f)
	, m_rotation(0.0f, 0.0f, 0.0f)
	, m_scale(1.0f, 1.0f, 1.0f)
{
	m_matrix = DirectX::SimpleMath::Matrix::Identity;
}


GameObject::~GameObject()
{
}
