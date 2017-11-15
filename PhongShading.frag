#version 330
in vec3 InterpolatedColor;
in vec3 PixelPosition;

out vec4 FragColor;

uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform vec3 CameraPosition;

void main()
{
	vec3 ambient = 0.1/* LightColor;
	vec3 diffuse = 

	FragColor = vec4(InterpolatedColor, 1.0f);
}