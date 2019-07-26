layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 in_tex_coord;

uniform vec2 position;
uniform vec2 size; 
uniform vec2 screen_resolution;

out vec2 tex_coord;

void main() {
  gl_Position = vec4(pos, 1.0, 1.0);
  tex_coord = in_tex_coord;
}
