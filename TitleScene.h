#pragma once
#include "GameScene.h"

// タイトルシーン
class TitleScene :public GameScene
{
public: // 基本

	// コンストラクタ
	TitleScene();
	// デストラクタ
	~TitleScene();

public: // 関数

	// 初期化
	void Initialize() override;
	// 更新
	void Update() override;
	// 描画
	void Render() override;
	// 後処理
	void Finalize() override;

};

