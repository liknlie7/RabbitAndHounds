#pragma once
#include <SimpleMath.h>
#include "GameContext.h"
#include "DeviceResources.h"
#include "Utilities.h"

// �J�����N���X
class FixCamera
{
public: // ��{

	// �R���X�g���N�^
	FixCamera();

public: // �A�N�Z�T

	// �r���[�s��擾
	DirectX::SimpleMath::Matrix GetViewMatrix() const
	{
		return m_view;
	}

	// �����_�̐ݒ�
	void SetTargetPosition(const DirectX::SimpleMath::Vector3& target)
	{
		m_target = target;
	}

	// ���_�̐ݒ�
	void SetEyePosition(const DirectX::SimpleMath::Vector3& eye)
	{
		m_eye = eye;
	}

	// ViewPort�̎擾
	DirectX::SimpleMath::Matrix GetViewPort()
	{
		m_viewPort;
	}

public: // �֐�

	// ������
	void Initialize();
	// �X�V
	void Update();

public: // �萔

	// ���_
	static const DirectX::SimpleMath::Vector3 EYE_VEC;
	// �J������
	static const DirectX::SimpleMath::Vector3 UP_VEC;

private: // �ϐ�

	// �r���[
	DirectX::SimpleMath::Matrix  m_view;
	
	// ���_
	DirectX::SimpleMath::Vector3 m_eye;

	// �����_
	DirectX::SimpleMath::Vector3 m_target;

	// �J������
	DirectX::SimpleMath::Vector3 m_up;

	// ViewPort
	DirectX::SimpleMath::Matrix	 m_viewPort;
};

