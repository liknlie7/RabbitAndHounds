#pragma once

#include <SimpleMath.h>
#include <Mouse.h>
#include <Model.h>
#include <Effects.h>
#include <CommonStates.h>

#include "GameObject.h"
#include "GameContext.h"
#include "DeviceResources.h"
#include "Projection.h"

// 猟犬クラス
class Hound : public GameObject
{
public: // 基本

	// コンストラクタ
	Hound();
	// デストラクタ
	~Hound();

public: // 関数

	// 初期化
	void Initialize(DirectX::SimpleMath::Vector3 startPos);

	// 更新
	void Update() override;

	// 描画
	void Render(const DirectX::SimpleMath::Matrix& view) override;

private: // 定数

	// モデルの大きさ
	static const DirectX::SimpleMath::Vector3 MODEL_SCALE;

private: // 変数

	// 猟犬
	std::unique_ptr<DirectX::Model>			m_pModel;
};

