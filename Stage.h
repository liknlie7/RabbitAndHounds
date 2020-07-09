#pragma once

#include <Model.h>
#include <SimpleMath.h>
#include <Effects.h>
#include <CommonStates.h>

#include "GameObject.h"
#include "GameContext.h"
#include "DeviceResources.h"
#include "Projection.h"

class Stage : public GameObject
{
public: // 基本

	// コンストラクタ
	Stage();
	// デストラクタ
	~Stage();

public: // 関数

	// 初期化
	void Initialize();
	// 更新
	void Update() override;
	// 描画
	void Render(const DirectX::SimpleMath::Matrix& view) override;

private: // 変数

	// ステージ
	std::unique_ptr<DirectX::Model>		m_pModel;

};

