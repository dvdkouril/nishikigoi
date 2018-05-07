#version 410

in GSOUTPUT
{
  vec2 uv;
  vec3 viewPos;
  float radius;
  vec4 color;
  flat int instanceId;
  flat int atomId;
} INPUT;

uniform float Scale;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

layout(location = 0) out vec4 out_color;
layout(location = 1) out vec4 out_normal;
layout(location = 2) out vec4 out_viewPos;
layout(location = 3) out vec4 out_instanceId;
layout(location = 4) out vec4 out_atomId;

void main(void)
{
  float lensqr = dot(INPUT.uv, INPUT.uv);
  if (lensqr > 1.0) discard;

  vec3 normal = vec3(INPUT.uv.x, INPUT.uv.y, sqrt(1.0 - lensqr));
  normal = normalize(normal);
  vec3 normalOut = normal * 0.5 + 0.5;
  out_normal = vec4(normalOut, 1.0);

  //gl_FragDepth = 0.5; // to demostrate z-fighting

  vec3 fragViewPos = INPUT.viewPos;
  fragViewPos.z += INPUT.radius * Scale * sqrt(1.0 - lensqr);
  out_viewPos = vec4(fragViewPos.x, fragViewPos.y, fragViewPos.z, 1.0); // view space position buffer, for ssao

  vec4 fragPosClip = projectionMatrix * vec4(fragViewPos, 1.0);
  vec3 fragPosNDC = fragPosClip.xyz / fragPosClip.w;
  float n = gl_DepthRange.near;
  float f = gl_DepthRange.far;
  float fragPosDepth = ((f - n) * fragPosNDC.z / 2.0) + ((f + n) / 2.0);
  gl_FragDepth = fragPosDepth;

  out_color = INPUT.color;
  out_instanceId = vec4(float(INPUT.instanceId), 0, 0, 1.0);
  out_atomId = vec4(float(INPUT.atomId), 0, 0, 1.0);

}
