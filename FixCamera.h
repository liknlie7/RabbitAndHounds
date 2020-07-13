#pragma once
#include <SimpleMath.h>
#include "GameContext.h"
#include "DeviceResources.h"
#include "Utilities.h"

// カメラクラス
class FixCamera
{
public: // 基本

	// コンストラクタ
	FixCamera();

public: // アクセサ

	// ビュー行列取得
	DirectX::SimpleMath::Matrix GetViewMatrix() const
	{
		return m_view;
	}

	// 注視点の設定
	void SetTargetPosition(const DirectX::SimpleMath::Vector3& target)
	{
		m_target = target;
	}

	// 視点の設定
	void SetEyePosition(const DirectX::SimpleMath::Vector3& eye)
	{
		m_eye = eye;
	}

	// ViewPortの取得
	DirectX::SimpleMath::Matrix GetViewPort()
	{
		m_viewPort;
	}

public: // 関数

	// 初期化
	void Initialize();
	// 更新
	void Update();

public: // 定数

	// 視点
	static const DirectX::SimpleMath::Vector3 EYE_VEC;
	// カメラ上
	static const DirectX::SimpleMath::Vector3 UP_VEC;

private: // 変数

	// ビュー
	DirectX::SimpleMath::Matrix  m_view;
	
	// 視点
	DirectX::SimpleMath::Vector3 m_eye;

	// 注視点
	DirectX::SimpleMath::Vector3 m_target;

	// カメラ上
	DirectX::SimpleMath::Vector3 m_up;

	// ViewPort
	DirectX::SimpleMath::Matrix	 m_viewPort;
};

