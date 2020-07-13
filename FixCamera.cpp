#include "pch.h"
#include "FixCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

// 視点
const Vector3 FixCamera::EYE_VEC = DirectX::SimpleMath::Vector3(0.0f, -100.0f, 0.0f);
// カメラの向き					   
const Vector3 FixCamera::UP_VEC = DirectX::SimpleMath::Vector3(0.0f, 0.0f, -1.0f);

// コンストラクタ
FixCamera::FixCamera()
{
	// 視点
	m_eye = EYE_VEC;
	
	// 注視点
	m_target = Vector3(0.0f, 0.0f, 0.0f);
	
	// カメラ上
	m_up = UP_VEC;

	// ビューポートの作成
	RECT size = GameContext::Get<DX::DeviceResources>()->GetOutputSize();
	m_viewPort =
		Matrix::CreateScale(Vector3(.5f, -.5f, 1.f)) *
		Matrix::CreateTranslation(Vector3(.5f, .5f, 0.f)) *
		Matrix::CreateScale(Vector3(float(size.right), float(size.bottom), 1.f));
}

// 初期化
void FixCamera::Initialize()
{
	m_view = Matrix::CreateLookAt(m_eye, m_target, m_up);
}

// 更新
void FixCamera::Update()
{
	m_view = Matrix::CreateLookAt(m_eye, m_target, m_up);
}