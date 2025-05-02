#version 460 core
    precision mediump float;
    uniform vec3 colour;
    out vec4 FragColour;
    void main()
    {
        FragColour = vec4(colour, 1.0f);
    }