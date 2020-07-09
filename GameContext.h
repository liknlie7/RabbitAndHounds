#pragma once

#include "ServiceLocator.h"

// �Q�[���R���e�L�X�g
class GameContext final
{
public: // �֐�

	// �|�C���^�Ŏ󂯎��
	template<typename Context, typename ConcreteContext>
	static void Register(ConcreteContext* context)
	{
		// �o�^
		ServiceLocator<Context>::Register(context);
	}

	// unique_ptr�Ŏ󂯎��
	template<typename Context, typename ConcreteContext>
	static void Register(std::unique_ptr<ConcreteContext>& context)
	{
		// �o�^
		ServiceLocator<Context>::Register(context);
	}

	// �E�Ӓl�Q�ƌ^�Ŏ󂯎��
	template<typename Context, typename ConcreteContext>
	static void Register(std::unique_ptr<ConcreteContext>&& context)
	{
		// �o�^
		ServiceLocator<Context>::Register(std::move(context));
	}

	// �擾
	template<typename Context>
	static Context* Get()
	{
		return ServiceLocator<Context>::Get();
	}

	// ����
	template<typename Context>
	static void Reset()
	{
		ServiceLocator<Context>::Reset();
	}
};
