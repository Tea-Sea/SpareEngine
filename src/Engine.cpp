#include "headers/Engine.hpp"

#include <stdexcept>

Engine* Engine::instance = nullptr;

Engine::Engine(const std::string& title, int width, int height) 
    :   m_windowManager(title.c_str(), width, height),
        m_renderer(m_windowManager.getWindow()),
        m_sceneManager(m_windowManager.getWindow()),
        m_inputManager()
        
{
    // Check if engine instance already exists
    if (instance == nullptr) {
        instance = this;
    } else {
        throw std::logic_error("Engine constructor called when an instance is already created.");
    }

    // TODO: Check MIX_Init       
}

Engine::~Engine()
{
    m_renderer.~Renderer();
    m_windowManager.~WindowManager();
    m_inputManager.~InputManager();
    m_sceneManager.~SceneManager();
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

float Engine::calculateDeltaTime()
{
    float currentTick = SDL_GetTicks();
    dt = (currentTick - startTick) / 1000.0f; // Convert to seconds

    // Update startTicks for next frame
    startTick = currentTick;
    std::cout << dt << "\n";
    return dt;
}

bool Engine::run()
{
    startTick = SDL_GetTicks();
    // Main Loop
    while (!m_inputManager.getQuitRequested())
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            m_inputManager.update(event);
            m_windowManager.update(event);
        }
        
        m_sceneManager.updateCurrentScene(calculateDeltaTime());

        m_renderer.renderLoop(m_windowManager.getWindow(), m_sceneManager.getCurrentScene()->prepareRenderData());
        
        SDL_Delay(0.5);
    }
    return 0;
}