#version 320 es
    precision mediump float;
    uniform vec3 colour;
    out vec4 FragColor;
    void main()
    {
        FragColor = vec4(colour, 1.0f);
    }