#pragma once
#include "GameScene.h"
#include "Stage.h"
#include "FixCamera.h"

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

private: // 変数

	// ステージ
	std::unique_ptr<Stage>			m_pStage;

	// 固定カメラ
	std::unique_ptr<FixCamera>		m_pFixCamera;

};

