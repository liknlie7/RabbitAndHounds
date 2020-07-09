#pragma once

#include <cassert>
#include <memory>

// �T�[�r�X���P�[�^�[
template<typename Service>
class ServiceLocator final
{
private: // �N���X�錾

	// �C���^�[�t�F�[�X
	class IServiceHolder;

	// �|�C���^�i�[�p
	template<typename ConcreteService>
	class ServicePtrHolder;

	// unique_ptr�i�[�p
	template<typename ConcreteService>
	class ServiceRefHolder;

	template<typename ConcreteService>
	class ServiceValHolder;


private: // �ϐ�

	static std::unique_ptr<IServiceHolder> s_serviceHolder;


public: // �֐�

	// �|�C���^�œo�^
	template<typename ConcreteService>
	static void Register(ConcreteService* service)
	{
		s_serviceHolder = std::make_unique<ServicePtrHolder<ConcreteService>>(service);
	}

	// unique_ptr�œo�^
	template<typename ConcreteService>
	static void Register(std::unique_ptr<ConcreteService>& service)
	{
		s_serviceHolder = std::make_unique<ServiceRefHolder<ConcreteService>>(service);
	}


	template<typename ConcreteService>
	static void Register(std::unique_ptr<ConcreteService>&& service)
	{
		s_serviceHolder = std::make_unique<ServiceValHolder<ConcreteService>>(std::move(service));
	}

public: // �A�N�Z�T

	// �擾
	static Service* Get()
	{
		// �o�^����Ă��Ȃ��Ȃ�I��
		assert(s_serviceHolder && "The service has not been registered.");

		return s_serviceHolder->Get();
	}

	// ����
	static void Reset()
	{
		s_serviceHolder.reset();
	}
};


// �C���^�[�t�F�[�X
template<typename Service>
class ServiceLocator<Service>::IServiceHolder
{
public: // ��{

	// �R���X�g���N�^
	virtual ~IServiceHolder() = default;
	// �f�X�g���N�^
	virtual Service* Get() const = 0;
};



template<typename Service>
template<typename ConcreteService>
class ServiceLocator<Service>::ServicePtrHolder final : public IServiceHolder
{
private:
	ConcreteService* m_service;


public:
	ServicePtrHolder(ConcreteService* service)
		: m_service(service)
	{
	}


	Service* Get() const
	{
		return m_service;
	}
};



template<typename Service>
template<typename ConcreteService>
class ServiceLocator<Service>::ServiceRefHolder final : public IServiceHolder
{
private:
	std::unique_ptr<ConcreteService>& m_service;


public:
	ServiceRefHolder(std::unique_ptr<ConcreteService>& service)
		: m_service(service)
	{
	}


	Service* Get() const
	{
		return m_service.get();
	}
};



template<typename Service>
template<typename ConcreteService>
class ServiceLocator<Service>::ServiceValHolder final : public IServiceHolder
{
private:
	std::unique_ptr<ConcreteService> m_service;


public:
	ServiceValHolder(std::unique_ptr<ConcreteService>&& service)
		: m_service(std::move(service))
	{
	}


	Service* Get() const
	{
		return m_service.get();
	}
};



template<typename Service>
std::unique_ptr<typename ServiceLocator<Service>::IServiceHolder> ServiceLocator<Service>::s_serviceHolder;
