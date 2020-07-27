#pragma once

#include <SimpleMath.h>
#include <Mouse.h>
#include <Model.h>
#include <Effects.h>
#include <CommonStates.h>

#include "GameObject.h"
#include "GameContext.h"
#include "DeviceResources.h"
#include "Projection.h"

// ���N���X
class Hound : public GameObject
{
public: // ��{

	// �R���X�g���N�^
	Hound();
	// �f�X�g���N�^
	~Hound();

public: // �֐�

	// ������
	void Initialize(DirectX::SimpleMath::Vector3 startPos);

	// �X�V
	void Update() override;

	// �`��
	void Render(const DirectX::SimpleMath::Matrix& view) override;

private: // �萔

	// ���f���̑傫��
	static const DirectX::SimpleMath::Vector3 MODEL_SCALE;

private: // �ϐ�

	// ��
	std::unique_ptr<DirectX::Model>			m_pModel;
};

