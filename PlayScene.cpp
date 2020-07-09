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
}

// �X�V
void PlayScene::Update()
{
}

// �`��
void PlayScene::Render()
{
	m_pStage->Render();
}

// �㏈��
void PlayScene::Finalize()
{
}
