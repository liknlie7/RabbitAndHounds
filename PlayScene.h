#pragma once
#include "GameScene.h"

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

};

