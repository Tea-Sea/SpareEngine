#version 460 core

    in vec2 TexCoord;
    out vec4 FragColour;

    uniform vec3 colour;
    uniform sampler2D textureImage;

    void main()
    {
        FragColour = texture(textureImage, TexCoord);
    }