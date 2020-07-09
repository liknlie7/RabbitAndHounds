#pragma once

#include <SimpleMath.h>

// �Q�[���I�u�W�F�N�g
class GameObject
{
public: // ��{

	// �R���X�g���N�^
	GameObject();
	// �f�X�g���N�^
	virtual ~GameObject();

public: // �֐�

	// �X�V
	virtual void Update() = 0;
	// �`��
	virtual void Render(const DirectX::SimpleMath::Matrix& view) = 0;

protected: // �ϐ�

	// ���W
	DirectX::SimpleMath::Vector3 m_position;
	// ��]
	DirectX::SimpleMath::Vector3 m_rotation;
	// �傫��
	DirectX::SimpleMath::Vector3 m_scale;
	// �s��
	DirectX::SimpleMath::Matrix  m_matrix;
};

