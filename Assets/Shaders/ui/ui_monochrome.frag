precision highp float;

in vec2 tex_coord;
out vec4 color;

uniform vec4 uniform_color;
uniform sampler2D in_texture;

void main() {
  color = uniform_color;
  color.a = texture(in_texture, tex_coord).r;
}
