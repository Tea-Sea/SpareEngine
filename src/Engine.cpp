#include "headers/Engine.hpp"

#include <stdexcept>

Engine* Engine::instance = nullptr;

Engine::Engine(const std::string& title, int width, int height) 
    :   m_windowManager(title.c_str(), width, height),
        m_renderer(m_windowManager.getWindow()),
        m_inputManager(),
        m_sceneManager()
{
    // Check if engine instance already exists
    if (instance == nullptr) {
        instance = this;
    } else {
        throw std::logic_error("Engine constructor called when an instance is already created.");
    }

    // Initialise SDL
    if( !SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) )
    {
        throw std::logic_error("Failed to initialise SDL library.");
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

bool Engine::run()
{
    // Main Loop
    while (!m_inputManager.getQuitRequested())
    {
        m_inputManager.update();

        m_renderer.renderLoop(m_windowManager.getWindow(), m_sceneManager.getCurrentScene()->getObjectList());
        
        SDL_Delay(0.5);
    }
    return 0;
}