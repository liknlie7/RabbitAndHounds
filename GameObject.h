#pragma once

#include <SimpleMath.h>

// ゲームオブジェクト
class GameObject
{
public: // 基本

	// コンストラクタ
	GameObject();
	// デストラクタ
	virtual ~GameObject();

public: // 関数

	// 更新
	virtual void Update() = 0;
	// 描画
	virtual void Render(const DirectX::SimpleMath::Matrix& view) = 0;

protected: // 変数

	// 座標
	DirectX::SimpleMath::Vector3 m_position;
	// 回転
	DirectX::SimpleMath::Vector3 m_rotation;
	// 大きさ
	DirectX::SimpleMath::Vector3 m_scale;
	// 行列
	DirectX::SimpleMath::Matrix  m_matrix;
};

