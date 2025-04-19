#include "headers/Player.hpp"

Player::Player()
{
    setName("Player");
}

Player::Player(glm::vec3 pos, int id)
{
    setName("Player");
    setID(id);
    setPosition(pos);
}

Player::~Player()
{
}