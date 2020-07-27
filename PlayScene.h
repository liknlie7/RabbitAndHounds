#pragma once
#include "GameScene.h"
#include "Stage.h"
#include "FixCamera.h"
#include "Hound.h"

// プレイシーン
class PlayScene : public GameScene
{
public: // 基本

	// コンストラクタ
	PlayScene();
	// デストラクタ
	~PlayScene();

public: // 関数

	// 初期化
	void Initialize() override;
	// 更新
	void Update() override;
	// 描画
	void Render() override;
	// 後処理
	void Finalize() override;

private: // 定数

	// 猟犬スタート地点
	static const DirectX::SimpleMath::Vector3 HOUND1_START_POS;
	static const DirectX::SimpleMath::Vector3 HOUND2_START_POS;
	static const DirectX::SimpleMath::Vector3 HOUND3_START_POS;

private: // 変数

	// ステージ
	std::unique_ptr<Stage>			m_pStage;

	// 固定カメラ
	std::unique_ptr<FixCamera>		m_pFixCamera;

	// 猟犬
	std::unique_ptr<Hound>			m_pHounds[3];

};

