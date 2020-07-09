#include "pch.h"
#include "Stage.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

// コンストラクタ
Stage::Stage()
{
	// エフェクトファクトリの作成
	EffectFactory* factory = new EffectFactory(GameContext::Get<DX::DeviceResources>()->GetD3DDevice());
	// テクスチャの読み込みパス指定
	factory->SetDirectory(L"Resources/Models");
	// ファイルを指定してモデルデータ読み込み
	m_pModel = Model::CreateFromCMO(GameContext::Get<DX::DeviceResources>()->GetD3DDevice(), L"Resources/Models/Stage.cmo", *factory);
	delete factory;
}

// デストラクタ
Stage::~Stage()
{
}

// 初期化
void Stage::Initialize()
{
}

// 更新
void Stage::Update()
{
}

// 描画
void Stage::Render(const Matrix & view)
{
	// モデル描画
	m_pModel->Draw(GameContext::Get<DX::DeviceResources>()->GetD3DDeviceContext(),
		*GameContext::Get<CommonStates>(), m_matrix, view, GameContext::Get<Projection>()->GetMatrix());
}
