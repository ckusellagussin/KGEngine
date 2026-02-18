#version 330 core
out vec4 FragColour;
in vec3 nColour;
void main()
{
FragColour = vec4(nColour, 1.0);
};