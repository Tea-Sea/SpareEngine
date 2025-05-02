#version 460 core

out vec4 FragColour;

uniform vec3 wireColour; // e.g., vec3(1.0, 1.0, 1.0) for white

void main()
{
    FragColour = vec4(wireColour, 1.0);
}