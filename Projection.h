#pragma once

#include "SimpleMath.h"

// �v���W�F�N�V����
class Projection final
{
public: // ��{

	// �R���X�g���N�^
	Projection() = default;
	// �f�X�g���N�^
	~Projection() = default;

public: // �A�N�Z�T

	// �s��̎擾
	const DirectX::SimpleMath::Matrix& GetMatrix() const;

public: // �֐�

	// �ˉe�s��̍쐬
	void SetPerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane);

private: // �ϐ�

	// �s��
	DirectX::SimpleMath::Matrix m_matrix;
};


// �s��̎擾
inline const DirectX::SimpleMath::Matrix& Projection::GetMatrix() const
{
	return m_matrix;
}

// �ˉe�s��̍쐬
inline void Projection::SetPerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	m_matrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fov, aspectRatio, nearPlane, farPlane);
}