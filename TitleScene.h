#pragma once
#include "GameScene.h"

// �^�C�g���V�[��
class TitleScene :public GameScene
{
public: // ��{

	// �R���X�g���N�^
	TitleScene();
	// �f�X�g���N�^
	~TitleScene();

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

