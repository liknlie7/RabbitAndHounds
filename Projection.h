#pragma once

#include "SimpleMath.h"

// プロジェクション
class Projection final
{
public: // 基本

	// コンストラクタ
	Projection() = default;
	// デストラクタ
	~Projection() = default;

public: // アクセサ

	// 行列の取得
	const DirectX::SimpleMath::Matrix& GetMatrix() const;

public: // 関数

	// 射影行列の作成
	void SetPerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane);

private: // 変数

	// 行列
	DirectX::SimpleMath::Matrix m_matrix;
};


// 行列の取得
inline const DirectX::SimpleMath::Matrix& Projection::GetMatrix() const
{
	return m_matrix;
}

// 射影行列の作成
inline void Projection::SetPerspectiveFieldOfView(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	m_matrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fov, aspectRatio, nearPlane, farPlane);
}