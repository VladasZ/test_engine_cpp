
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
  float size_ratio = size.x / size.y;

  vec2 translation = vec2(
    (2.0 / resolution.x) * position.x - 1.0,
    (2.0 / resolution.y) * position.y - 1.0
  );

  gl_Position = vec4(vertex_position.xy, 0.0, 1.0);

  gl_Position.x *= size_ratio;
  gl_Position = gl_Position * rotation_matrix;


  //gl_Position.xy += translation;

  tex_coord = in_tex_coord;
}
