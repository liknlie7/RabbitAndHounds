#pragma once

#include "ServiceLocator.h"

// ゲームコンテキスト
class GameContext final
{
public: // 関数

	// ポインタで受け取る
	template<typename Context, typename ConcreteContext>
	static void Register(ConcreteContext* context)
	{
		// 登録
		ServiceLocator<Context>::Register(context);
	}

	// unique_ptrで受け取る
	template<typename Context, typename ConcreteContext>
	static void Register(std::unique_ptr<ConcreteContext>& context)
	{
		// 登録
		ServiceLocator<Context>::Register(context);
	}

	// 右辺値参照型で受け取る
	template<typename Context, typename ConcreteContext>
	static void Register(std::unique_ptr<ConcreteContext>&& context)
	{
		// 登録
		ServiceLocator<Context>::Register(std::move(context));
	}

	// 取得
	template<typename Context>
	static Context* Get()
	{
		return ServiceLocator<Context>::Get();
	}

	// 消去
	template<typename Context>
	static void Reset()
	{
		ServiceLocator<Context>::Reset();
	}
};
