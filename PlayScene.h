#pragma once
#include "GameScene.h"
#include "Stage.h"
#include "FixCamera.h"

// �v���C�V�[��
class PlayScene : public GameScene
{
public: // ��{

	// �R���X�g���N�^
	PlayScene();
	// �f�X�g���N�^
	~PlayScene();

public: // �֐�

	// ������
	void Initialize() override;
	// �X�V
	void Update() override;
	// �`��
	void Render() override;
	// �㏈��
	void Finalize() override;

private: // �ϐ�

	// �X�e�[�W
	std::unique_ptr<Stage>			m_pStage;

	// �Œ�J����
	std::unique_ptr<FixCamera>		m_pFixCamera;

};

