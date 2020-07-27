#pragma once
#include "GameScene.h"
#include "Stage.h"
#include "FixCamera.h"
#include "Hound.h"

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

private: // �萔

	// ���X�^�[�g�n�_
	static const DirectX::SimpleMath::Vector3 HOUND1_START_POS;
	static const DirectX::SimpleMath::Vector3 HOUND2_START_POS;
	static const DirectX::SimpleMath::Vector3 HOUND3_START_POS;

private: // �ϐ�

	// �X�e�[�W
	std::unique_ptr<Stage>			m_pStage;

	// �Œ�J����
	std::unique_ptr<FixCamera>		m_pFixCamera;

	// ��
	std::unique_ptr<Hound>			m_pHounds[3];

};

