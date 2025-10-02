#version 460 core
out vec4 FragColor;

in vec3 ourColor; // Input color from vertex shader
in vec4 ourPos;

void main()
{
    FragColor = ourPos;
}
