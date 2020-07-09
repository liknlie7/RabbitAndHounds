#include "pch.h"

#include <cassert>

#include "GameSceneManager.h"

// �R���X�g���N�^
GameSceneManager::GameSceneManager()
	: m_sceneFactories()
	, m_activeScene(nullptr)
	, m_nextSceneName()
{
}

// �f�X�g���N�^
GameSceneManager::~GameSceneManager()
{
}


void GameSceneManager::SetStartScene(const std::string& _sceneName)
{
	RequestScene(_sceneName);
}


void GameSceneManager::Update()
{
	if (!m_nextSceneName.empty())
	{
		ChangeScene();
	}

	assert(m_activeScene && "There is no active scene.");
	m_activeScene->Update();
}


void GameSceneManager::Render()
{
	assert(m_activeScene && "There is no active scene.");
	m_activeScene->Render();
}


void GameSceneManager::RequestScene(const std::string& _sceneName)
{
	assert(m_sceneFactories.count(_sceneName) == 1 && "A GameScene with this name is not registered.");

	m_nextSceneName = _sceneName;
}


void GameSceneManager::ChangeScene()
{
	if (m_activeScene)
	{
		m_activeScene->Finalize();
	}

	m_activeScene = m_sceneFactories[m_nextSceneName]();
	m_activeScene->Initialize();

	m_nextSceneName.clear();
}