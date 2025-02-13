#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform float horiOffset;
uniform float vertiOffset;
out vec3 ourColor;
out vec4 ourPosition;

void main()
{
    gl_Position = vec4(aPos.x + horiOffset, aPos.y + vertiOffset / 1.5, aPos.z, 1.0);
	ourPosition = gl_Position;
	ourColor = aColor;
}
