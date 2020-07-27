#include "pch.h"
#include "PlayScene.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

const Vector3 PlayScene::HOUND1_START_POS = Vector3(0.0f, 3.0f, -20.0f);
const Vector3 PlayScene::HOUND2_START_POS = Vector3(10.0f, 3.0f, -10.0f);
const Vector3 PlayScene::HOUND3_START_POS = Vector3(-10.0f, 3.0f, -10.0f);

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

	// 猟犬作成
	for (int i = 0; i < 3; i++)
	{
		m_pHounds[i] = make_unique<Hound>();
	}
	m_pHounds[0]->Initialize(HOUND1_START_POS);
	m_pHounds[1]->Initialize(HOUND2_START_POS);
	m_pHounds[2]->Initialize(HOUND3_START_POS);

}

// 更新
void PlayScene::Update()
{
	// 固定カメラ更新
	m_pFixCamera->Update();

	// 猟犬更新
	for (int i = 0; i < 3; i++)
	{
		m_pHounds[i]->Update();
	}
}

// 描画
void PlayScene::Render()
{
	// ステージ描画
	m_pStage->Render(m_pFixCamera->GetViewMatrix());

	// 猟犬描画
	for (int i = 0; i < 3; i++)
	{
		m_pHounds[i]->Render(m_pFixCamera->GetViewMatrix());
	}
}

// 後処理
void PlayScene::Finalize()
{
}
