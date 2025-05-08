#include "headers/ResourceManager.hpp"


ResourceManager::ResourceManager()
{
    loadAll();
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::loadShader(std::string name, std::string vertexSrc, std::string fragSrc)
{
    // Shader shader(vertexSrc, fragSrc);
    // shaderIDs[name] = shader;
    shaders.emplace(name, Shader(vertexSrc, fragSrc));
}

Shader* ResourceManager::getShader(const std::string& name)
{
    auto result = shaders.find(name);
    if (result != shaders.end()) {
        return &result->second;
    }
    std::cerr << "Unable to find shader: " << name;
    return nullptr;
}

void ResourceManager::loadTexture(std::string name, std::string textureSrc)
{
    // TODO: Add texture loading
}

Texture* ResourceManager::getTexture(const std::string& name)
{
    auto result = textures.find(name);
    if (result != textures.end()) {
        return &result->second;
    }
    std::cerr << "Unable to find texture: " << name;
    return nullptr;
}

void ResourceManager::loadMesh(std::string name, std::string meshSrc)
{
    // TODO: Add mesh loading

}

Mesh* ResourceManager::getMesh(const std::string& name)
{
    auto result = meshes.find(name);
    if (result != meshes.end()) {
        return &result->second;
    }
    std::cerr << "Unable to find texture: " << name;
    return nullptr;
}

// For testing
void ResourceManager::loadAll()
{
    // Check if the directory exists
    if (!std::filesystem::exists("assets/shaders/") || !std::filesystem::is_directory("assets/shaders/")) {
        std::cerr << "Invalid directory path: assets/shaders/"<< std::endl;
        return;
    }

    // Iterate through the files in the directory
    for (const auto& entry : std::filesystem::directory_iterator("assets/shaders/")) {
        // Check if the entry is a file (not a subdirectory)
        if (std::filesystem::is_regular_file(entry)) {

            // Check if it is a .frag file
            if (entry.path().extension() == ".frag")
            {
                // Check if corresponding vert file exists
                std::filesystem::path newPath = entry.path();
                newPath.replace_extension(".vert");
                if (std::filesystem::exists(newPath))
                {
                    // Load shader using vert and frag
                    loadShader(entry.path().stem(), newPath.filename(), entry.path().filename());
                }
                else {
                    // Load shader using default vert
                    loadShader(entry.path().stem(), "default.vert", entry.path().filename());
                }
            }
        }
    }
}