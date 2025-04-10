#include "headers/Engine.hpp"

#include <iostream>

using namespace std;

int main ()
{
    try {
        Engine::getInstance().run();
    } catch (const std::exception& ex) {
        std::cout << "Game crashed\n\n" << std::endl;
        std::cout << "Exception: " << ex.what() << std::endl;
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
    }

    return 0;
}