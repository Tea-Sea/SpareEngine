#pragma once

#include "../headers/GameObject.hpp"
#include "../headers/Camera.hpp"


#include <vector>
#include <memory>

struct RenderData {
    std::vector<GameObject*> objects;
    Camera* camera;
    // std::vector<Light*> lights;
};
