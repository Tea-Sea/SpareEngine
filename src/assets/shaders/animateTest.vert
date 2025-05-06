#version 460 core

// Standard input attributes (adjust layout locations if needed)
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;      // Optional
layout(location = 2) in vec2 aTexCoord;    // Optional
layout(location = 3) in vec4 aColour;       // Optional

// Output to the fragment shader
out vec2 TexCoord;
out vec4 VertexColour;
out vec3 FragPos;
out vec3 Normal;

// Uniforms for transformations
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Compute world-space position
    vec4 worldPosition = model * vec4(aPosition, 1.0);
    FragPos = worldPosition.xyz;

    // Transform normal (if needed)
    Normal = mat3(transpose(inverse(model))) * aNormal;

    // Pass through texture coordinates and colour
    TexCoord = aTexCoord;
    VertexColour = aColour;

    // Final vertex position in clip space
    gl_Position = projection * view * worldPosition;
}