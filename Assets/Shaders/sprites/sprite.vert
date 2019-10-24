
#include "transforms.glsl"

layout (location = 0) in vec2 vertex_position;
layout (location = 1) in vec2 in_tex_coord;

uniform vec2 position;
uniform vec2 size; 
uniform vec2 resolution;
uniform float rotation;

out vec2 tex_coord;

void main() {

  vec2 size_scale = vec2(size.x / resolution.x,
					               size.y / resolution.y);

  vec2 position_scale = vec2(2.0 / resolution.x,
							               2.0 / resolution.y);

  vec2 shift = position * position_scale;

  shift.y -= 2.0;


  vec4 rotated_vector = rotation_z(rotation) * vec4(vertex_position, 0, 1);

  vec2 rotated_pos = rotated_vector.xy;

  vec2 scaled_pos = rotated_pos * size_scale;

  scaled_pos += vec2(-1.0, 1.0);
  
  gl_Position = vec4(scaled_pos + shift, 1.0, 1.0);
  tex_coord = in_tex_coord;
}
