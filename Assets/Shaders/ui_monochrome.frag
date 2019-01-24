precision highp float;

in vec2 tex_coord;
out vec4 color;

uniform sampler2D in_texture;

void main() {
  color = vec4(1, 1, 1, texture(in_texture, tex_coord).r);;
}
