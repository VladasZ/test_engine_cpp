layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 in_tex_coord;

uniform vec2 position;
uniform vec2 size; 
uniform vec2 resolution;

out vec2 tex_coord;

void main() {

  vec2 scale = vec2(size.x / resolution.x,
					size.y / resolution.y);

  vec2 position_scale = vec2(2.0 / resolution.x,
							 2.0 / resolution.y);

  vec2 scaled_pos = pos * scale + vec2(-1.0, 1.0);

  vec2 shift = position * position_scale;

  shift.y -= 2.0;
  
  gl_Position = vec4(scaled_pos + shift, 1.0, 1.0);
  tex_coord = in_tex_coord;
}
