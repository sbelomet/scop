#version 460 core
out vec4 FragColor;

in vec3 ourColor; // Input color from vertex shader
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;

void main()
{
	vec4 tex1 = texture(texture1, TexCoord);
    vec4 tex2 = texture(texture2, TexCoord);
    FragColor = mix(tex1, tex2, mixValue);
}
