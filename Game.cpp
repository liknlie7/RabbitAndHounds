//
// Game.cpp
//

#include "pch.h"
#include "Game.h"

extern void ExitGame();

using namespace DirectX;
using namespace std;

using Microsoft::WRL::ComPtr;

Game::Game() noexcept(false)
{
    m_pDeviceResources = std::make_unique<DX::DeviceResources>();
    m_pDeviceResources->RegisterDeviceNotify(this);

	// �f�o�C�X���R���e�L�X�g�֓o�^
	GameContext::Register<DX::DeviceResources>(m_pDeviceResources);
}

// Initialize the Direct3D resources required to run.
void Game::Initialize(HWND window, int width, int height)
{
	// �}�E�X�̍쐬
	m_pMouse = make_unique<Mouse>();
	m_pMouse->SetWindow(window);

    m_pDeviceResources->SetWindow(window, width, height);

    m_pDeviceResources->CreateDeviceResources();
    CreateDeviceDependentResources();

	// �R�����X�e�[�g�̍쐬
	m_pState = make_unique<CommonStates>(m_pDeviceResources->GetD3DDevice());

    m_pDeviceResources->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();

    // TODO: Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */

	// �V�[���̓o�^
	m_pGameSceneManager = make_unique<GameSceneManager>();
	m_pGameSceneManager->RegisterScene<TitleScene>("Title");
	m_pGameSceneManager->RegisterScene<PlayScene>("Play");

	// �ŏ��̃V�[����ݒ�
	m_pGameSceneManager->SetStartScene("Play");
	// �V�[���}�l�[�W���[���R���e�L�X�g�֓o�^
	GameContext::Register<GameSceneManager>(m_pGameSceneManager);

}

#pragma region Frame Update
// Executes the basic game loop.
void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}

// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
    elapsedTime;

	// �V�[���̍X�V
	m_pGameSceneManager->Update();

}
#pragma endregion

#pragma region Frame Render
// Draws the scene.
void Game::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    Clear();

    m_pDeviceResources->PIXBeginEvent(L"Render");
    auto context = m_pDeviceResources->GetD3DDeviceContext();

    // TODO: Add your rendering code here.
    context;

	// �V�[���̕`��
	m_pGameSceneManager->Render();

    m_pDeviceResources->PIXEndEvent();

    // Show the new frame.
    m_pDeviceResources->Present();
}

// Helper method to clear the back buffers.
void Game::Clear()
{
    m_pDeviceResources->PIXBeginEvent(L"Clear");

    // Clear the views.
    auto context = m_pDeviceResources->GetD3DDeviceContext();
    auto renderTarget = m_pDeviceResources->GetRenderTargetView();
    auto depthStencil = m_pDeviceResources->GetDepthStencilView();

    context->ClearRenderTargetView(renderTarget, Colors::CornflowerBlue);
    context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    context->OMSetRenderTargets(1, &renderTarget, depthStencil);

    // Set the viewport.
    auto viewport = m_pDeviceResources->GetScreenViewport();
    context->RSSetViewports(1, &viewport);

    m_pDeviceResources->PIXEndEvent();
}
#pragma endregion

#pragma region Message Handlers
// Message handlers
void Game::OnActivated()
{
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowMoved()
{
    auto r = m_pDeviceResources->GetOutputSize();
    m_pDeviceResources->WindowSizeChanged(r.right, r.bottom);
}

void Game::OnWindowSizeChanged(int width, int height)
{
    if (!m_pDeviceResources->WindowSizeChanged(width, height))
        return;

    CreateWindowSizeDependentResources();

    // TODO: Game window is being resized.
}

// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width = 800;
    height = 600;
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Game::CreateDeviceDependentResources()
{
    auto device = m_pDeviceResources->GetD3DDevice();

    // TODO: Initialize device dependent objects here (independent of window size).
    device;
}

// Allocate all memory resources that change on a window SizeChanged event.
void Game::CreateWindowSizeDependentResources()
{
    // TODO: Initialize windows-size dependent objects here.

	// �E�C���h�E�T�C�Y����A�X�y�N�g����Z�o����
	RECT size = m_pDeviceResources->GetOutputSize();
	float aspectRatio = float(size.right) / float(size.bottom);

	// ��p��ݒ�
	float fovAngleY = XMConvertToRadians(45.0f);

	// �ˉe�s����쐬����
	m_pProjection = std::make_unique<Projection>();
	m_pProjection->SetPerspectiveFieldOfView(
		fovAngleY,
		aspectRatio,
		0.01f,
		100.0f
	);
	GameContext::Register<Projection>(m_pProjection);

}

void Game::OnDeviceLost()
{
    // TODO: Add Direct3D resource cleanup here.
}

void Game::OnDeviceRestored()
{
    CreateDeviceDependentResources();

    CreateWindowSizeDependentResources();
}
#pragma endregion
