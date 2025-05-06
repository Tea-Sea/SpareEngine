#version 460 core

    in vec2 TexCoord;
    out vec4 FragColour;

    uniform vec3 colour;
    uniform Sampler2D ourTexture;

    void main()
    {
        FragColour = texture(ourTexture, TexCoord);
    }