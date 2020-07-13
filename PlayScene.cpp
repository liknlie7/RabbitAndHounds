#include "pch.h"
#include "PlayScene.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

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
}

// �X�V
void PlayScene::Update()
{
	// �Œ�J�����X�V
	m_pFixCamera->Update();
}

// �`��
void PlayScene::Render()
{
	m_pStage->Render(m_pFixCamera->GetViewMatrix());
}

// �㏈��
void PlayScene::Finalize()
{
}
