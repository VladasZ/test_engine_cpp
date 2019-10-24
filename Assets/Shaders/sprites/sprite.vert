
#include "transforms.glsl"

layout (location = 0) in vec2 vertex_position;
layout (location = 1) in vec2 in_tex_coord;

uniform vec2 position;
uniform vec2 size; 
uniform vec2 resolution;
uniform float rotation;

out vec2 tex_coord;

void main() {

  mat4 rotation_matrix = rotation_z_matrix(rotation);

  mat4 scale_matrix = scale_matrix(
    size.x / resolution.x, 
    size.y / resolution.y
  );

  mat4 translation_matrix = translation_matrix(
    ((2.0 / resolution.x) * position.x) - 1.0,
    ((2.0 / resolution.x) * position.y) - 1.0
  );

//gl_Position = (scale_matrix * rotation_matrix * translation_matrix) * vec4(vertex_position.xy, 0.0, 1.0);
  //gl_Position = (translation_matrix * rotation_matrix * scale_matrix) * vec4(vertex_position.xy, 0.0, 1.0);

  gl_Position = vec4(vertex_position.xy, 0.0, 1.0) * (scale_matrix * rotation_matrix * translation_matrix);
//  gl_Position = vec4(vertex_position.xy, 0.0, 1.0) * (translation_matrix * rotation_matrix * scale_matrix);


  tex_coord = in_tex_coord;
}
