#version 410

in vec3 position;

out VSOUTPUT
{
  vec3 positionVS;
  int instanceId;
} OUTPUT;

uniform mat4 modelViewMatrix;
uniform int EnableLod;
uniform float FirstLevelBeginRange;
uniform float Scale;
uniform bool ScalePositions;


void main(void)
{

  vec3 pos = (modelViewMatrix * vec4(position, 1.0)).xyz;

  OUTPUT.positionVS = pos;
  OUTPUT.instanceId = 0;
}
