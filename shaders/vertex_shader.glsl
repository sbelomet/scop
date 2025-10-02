#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform float horizontalOffset;

out vec3 ourColor; // Output a color to the fragment shader
out vec4 ourPos;

void main()
{
	ourPos = vec4(aPos.x + horizontalOffset, aPos.y, aPos.z, 1.0);
	gl_Position = ourPos;
	ourColor = aColor;
}
