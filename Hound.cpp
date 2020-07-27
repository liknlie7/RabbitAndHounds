#include "pch.h"
#include "Hound.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

const Vector3 Hound::MODEL_SCALE = Vector3(0.13f, 0.13f, 0.13f);

// コンストラクタ
Hound::Hound()
{
	// エフェクトファクトリの作成
	EffectFactory* factory = new EffectFactory(GameContext::Get<DX::DeviceResources>()->GetD3DDevice());
	// テクスチャの読み込みパス指定
	factory->SetDirectory(L"Resources/Models");
	// ファイルを指定してモデルデータ読み込み
	m_pModel = Model::CreateFromCMO(GameContext::Get<DX::DeviceResources>()->GetD3DDevice(), L"Resources/Models/Hound.cmo", *factory);
	delete factory;

	// モデルの大きさ設定
	m_scale = MODEL_SCALE;
}

// デストラクタ
Hound::~Hound()
{
}

// 初期化
void Hound::Initialize(Vector3 startPos)
{
	m_position = startPos;
}

// 更新
void Hound::Update()
{
}

// 描画
void Hound::Render(const Matrix& view)
{
	Matrix scale = Matrix::CreateScale(m_scale);
	Matrix trans = Matrix::CreateTranslation(Vector3(m_position));
	m_matrix = scale * trans;
	// モデル描画
	m_pModel->Draw(GameContext::Get<DX::DeviceResources>()->GetD3DDeviceContext(),
		*GameContext::Get<CommonStates>(), m_matrix, view, GameContext::Get<Projection>()->GetMatrix());
}
