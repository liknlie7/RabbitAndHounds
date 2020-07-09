#include "pch.h"
#include "PlayScene.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

// コンストラクタ
PlayScene::PlayScene()
{
}

// デストラクタ
PlayScene::~PlayScene()
{
}

// 初期化
void PlayScene::Initialize()
{
	// ステージの作成
	m_pStage = make_unique<Stage>();
	m_pStage->Initialize();
}

// 更新
void PlayScene::Update()
{
}

// 描画
void PlayScene::Render()
{
	m_pStage->Render();
}

// 後処理
void PlayScene::Finalize()
{
}
