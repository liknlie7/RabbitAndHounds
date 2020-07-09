//
// Game.h
//

#pragma once

#include <CommonStates.h>

#include "DeviceResources.h"
#include "StepTimer.h"
#include "GameContext.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Mouse.h"
#include "Projection.h"
#include "GameSceneManager.h"

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
public:

    Game() noexcept(false);

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowMoved();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>    m_pDeviceResources;

    // Rendering loop timer.
    DX::StepTimer                           m_timer;

	// ゲームシーンマネージャー
	std::unique_ptr<GameSceneManager>       m_pGameSceneManager;

	// 射影行列
	std::unique_ptr<Projection>				m_pProjection;

	// マウス
	std::unique_ptr<DirectX::Mouse>			m_pMouse;

	// コモンステート
	std::unique_ptr<DirectX::CommonStates>	m_pState;

};