#include "pch.h"
#include "PlayScene.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

const Vector3 PlayScene::HOUND1_START_POS = Vector3(0.0f, 3.0f, -20.0f);
const Vector3 PlayScene::HOUND2_START_POS = Vector3(10.0f, 3.0f, -10.0f);
const Vector3 PlayScene::HOUND3_START_POS = Vector3(-10.0f, 3.0f, -10.0f);

// �R���X�g���N�^
PlayScene::PlayScene()
{
}

// �f�X�g���N�^
PlayScene::~PlayScene()
{
}

// ������
void PlayScene::Initialize()
{
	// �X�e�[�W�̍쐬
	m_pStage = make_unique<Stage>();
	m_pStage->Initialize();

	// �Œ�J�����̍쐬
	m_pFixCamera = make_unique<FixCamera>();
	m_pFixCamera->Initialize();
	GameContext::Register<FixCamera>(m_pFixCamera);

	// ���쐬
	for (int i = 0; i < 3; i++)
	{
		m_pHounds[i] = make_unique<Hound>();
	}
	m_pHounds[0]->Initialize(HOUND1_START_POS);
	m_pHounds[1]->Initialize(HOUND2_START_POS);
	m_pHounds[2]->Initialize(HOUND3_START_POS);

}

// �X�V
void PlayScene::Update()
{
	// �Œ�J�����X�V
	m_pFixCamera->Update();

	// ���X�V
	for (int i = 0; i < 3; i++)
	{
		m_pHounds[i]->Update();
	}
}

// �`��
void PlayScene::Render()
{
	// �X�e�[�W�`��
	m_pStage->Render(m_pFixCamera->GetViewMatrix());

	// ���`��
	for (int i = 0; i < 3; i++)
	{
		m_pHounds[i]->Render(m_pFixCamera->GetViewMatrix());
	}
}

// �㏈��
void PlayScene::Finalize()
{
}
