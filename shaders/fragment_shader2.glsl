#version 460 core
out vec4 FragColor;

//uniform vec4 ourColor; // Gets set in the main code

in vec3 ourColor; // Input color from vertex shader

void main()
{
    FragColor = vec4(ourColor, 0.5);
}
