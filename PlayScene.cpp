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

	// 固定カメラの作成
	m_pFixCamera = make_unique<FixCamera>();
	m_pFixCamera->Initialize();
	GameContext::Register<FixCamera>(m_pFixCamera);
}

// 更新
void PlayScene::Update()
{
	// 固定カメラ更新
	m_pFixCamera->Update();
}

// 描画
void PlayScene::Render()
{
	m_pStage->Render(m_pFixCamera->GetViewMatrix());
}

// 後処理
void PlayScene::Finalize()
{
}
