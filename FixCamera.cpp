#include "pch.h"
#include "FixCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

// ���_
const Vector3 FixCamera::EYE_VEC = DirectX::SimpleMath::Vector3(0.0f, -100.0f, 0.0f);
// �J�����̌���					   
const Vector3 FixCamera::UP_VEC = DirectX::SimpleMath::Vector3(0.0f, 0.0f, -1.0f);

// �R���X�g���N�^
FixCamera::FixCamera()
{
	// ���_
	m_eye = EYE_VEC;
	
	// �����_
	m_target = Vector3(0.0f, 0.0f, 0.0f);
	
	// �J������
	m_up = UP_VEC;

	// �r���[�|�[�g�̍쐬
	RECT size = GameContext::Get<DX::DeviceResources>()->GetOutputSize();
	m_viewPort =
		Matrix::CreateScale(Vector3(.5f, -.5f, 1.f)) *
		Matrix::CreateTranslation(Vector3(.5f, .5f, 0.f)) *
		Matrix::CreateScale(Vector3(float(size.right), float(size.bottom), 1.f));
}

// ������
void FixCamera::Initialize()
{
	m_view = Matrix::CreateLookAt(m_eye, m_target, m_up);
}

// �X�V
void FixCamera::Update()
{
	m_view = Matrix::CreateLookAt(m_eye, m_target, m_up);
}