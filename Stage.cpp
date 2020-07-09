#include "pch.h"
#include "Stage.h"

// �R���X�g���N�^
Stage::Stage()
{
	// �G�t�F�N�g�t�@�N�g���̍쐬
	DirectX::EffectFactory* factory = new DirectX::EffectFactory(GameContext::Get<DX::DeviceResources>()->GetD3DDevice());
	// �e�N�X�`���̓ǂݍ��݃p�X�w��
	factory->SetDirectory(L"Resources/Models");
	// �t�@�C�����w�肵�ă��f���f�[�^�ǂݍ���
	m_pModel = DirectX::Model::CreateFromCMO(GameContext::Get<DX::DeviceResources>()->GetD3DDevice(), L"Resources/Models/Stage.cmo", *factory);
	delete factory;
}

// �f�X�g���N�^
Stage::~Stage()
{
}

// ������
void Stage::Initialize()
{
}

// �X�V
void Stage::Update()
{
}

// �`��
void Stage::Render(const DirectX::SimpleMath::Matrix & view)
{
	// ���f���`��
	m_pModel->Draw(GameContext::Get<DX::DeviceResources>()->GetD3DDeviceContext(),
		*GameContext::Get<DirectX::CommonStates>(), m_matrix, view, GameContext::Get<Projection>()->GetMatrix());
}
