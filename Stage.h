#pragma once

#include <Model.h>
#include <SimpleMath.h>
#include <Effects.h>
#include <CommonStates.h>

#include "GameObject.h"
#include "GameContext.h"
#include "DeviceResources.h"
#include "Projection.h"

class Stage : public GameObject
{
public: // ��{

	// �R���X�g���N�^
	Stage();
	// �f�X�g���N�^
	~Stage();

public: // �֐�

	// ������
	void Initialize();
	// �X�V
	void Update() override;
	// �`��
	void Render(const DirectX::SimpleMath::Matrix& view) override;

private: // �ϐ�

	// �X�e�[�W
	std::unique_ptr<DirectX::Model>		m_pModel;

};

