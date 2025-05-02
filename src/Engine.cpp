#include "headers/Engine.hpp"

#include <stdexcept>

Engine* Engine::instance = nullptr;

Engine::Engine(const std::string& title, int width, int height)
    :   m_windowManager(title.c_str(), width, height),
        m_renderer(m_windowManager.getWindow()),
        m_sceneManager(m_windowManager.getWindow()),
        m_inputManager(),
        m_resourceManager()

{
    // Check if engine instance already exists
    if (instance == nullptr) {
        instance = this;
    } else {
        throw std::logic_error("Engine constructor called when an instance is already created.");
    }

    m_windowManager.setResizeCallback([&](float width, float height) {
        m_sceneManager.getCurrentScene()->getCamera()->setAspectRatio(width, height);
    });
    // TODO: Check MIX_Init
}

Engine::~Engine()
{
    m_renderer.~Renderer();
    m_windowManager.~WindowManager();
    m_inputManager.~InputManager();
    m_sceneManager.~SceneManager();
    m_resourceManager.~ResourceManager();
    SDL_Quit();
}

Engine& Engine::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Engine("Spare", 800, 600);
    }
    return *instance;
}

WindowManager* Engine::getWindow()
{
    return &m_windowManager;
}

Renderer* Engine::getRenderer()
{
    return &m_renderer;
}

InputManager* Engine::getInputManager()
{
    return &m_inputManager;
}

SceneManager* Engine::getSceneManager()
{
    return &m_sceneManager;
}

ResourceManager* Engine::getResourceManager()
{
    return &m_resourceManager;
}

float Engine::calculateDeltaTime()
{
    float currentTick = SDL_GetTicks();
    deltaTime = (currentTick - startTick) / 1000.0f; // Convert to seconds

    // Update startTicks for next frame
    startTick = currentTick;
    return deltaTime;
}

bool Engine::run()
{
    startTick = SDL_GetTicks();
    // Main Loop
    while (!m_inputManager.getQuitRequested())
    {
        calculateDeltaTime();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            m_inputManager.update(event);
            m_windowManager.update(event);
        }

        m_sceneManager.updateCurrentScene(deltaTime);

        m_renderer.renderLoop(m_windowManager.getWindow(), SDL_GetTicks() / 1000.0f, m_sceneManager.getCurrentScene()->prepareRenderData());

        // SDL_Delay(0.5);
    }
    return 0;
}