
#include "transforms.glsl"

layout (location = 0) in vec2 vertex_position;
layout (location = 1) in vec2 in_tex_coord;

uniform vec2 position;
uniform vec2 size;
uniform vec2 resolution;
uniform float rotation;

out vec2 tex_coord;

void main() {

  mat4 rotation_matrix = rotation_z_matrix(-rotation);

  gl_Position = vec4(vertex_position.xy, 0.0, 1.0);

  gl_Position.x *= size.x;
  gl_Position.y *= size.y;

  gl_Position = gl_Position * rotation_matrix;

  gl_Position.xy += position;

  gl_Position.x *= resolution.y / resolution.x;

  float scale = size.y / resolution.y;

  gl_Position.xy *= scale;

  tex_coord = in_tex_coord;
}
