#include "pch.h"
#include "Hound.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

const Vector3 Hound::MODEL_SCALE = Vector3(0.13f, 0.13f, 0.13f);

// �R���X�g���N�^
Hound::Hound()
{
	// �G�t�F�N�g�t�@�N�g���̍쐬
	EffectFactory* factory = new EffectFactory(GameContext::Get<DX::DeviceResources>()->GetD3DDevice());
	// �e�N�X�`���̓ǂݍ��݃p�X�w��
	factory->SetDirectory(L"Resources/Models");
	// �t�@�C�����w�肵�ă��f���f�[�^�ǂݍ���
	m_pModel = Model::CreateFromCMO(GameContext::Get<DX::DeviceResources>()->GetD3DDevice(), L"Resources/Models/Hound.cmo", *factory);
	delete factory;

	// ���f���̑傫���ݒ�
	m_scale = MODEL_SCALE;
}

// �f�X�g���N�^
Hound::~Hound()
{
}

// ������
void Hound::Initialize(Vector3 startPos)
{
	m_position = startPos;
}

// �X�V
void Hound::Update()
{
}

// �`��
void Hound::Render(const Matrix& view)
{
	Matrix scale = Matrix::CreateScale(m_scale);
	Matrix trans = Matrix::CreateTranslation(Vector3(m_position));
	m_matrix = scale * trans;
	// ���f���`��
	m_pModel->Draw(GameContext::Get<DX::DeviceResources>()->GetD3DDeviceContext(),
		*GameContext::Get<CommonStates>(), m_matrix, view, GameContext::Get<Projection>()->GetMatrix());
}
