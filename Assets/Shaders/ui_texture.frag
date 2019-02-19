precision highp float;

out vec4 color;
in vec2 tex_coord;

uniform sampler2D in_texture;

void main() {
  color = texture(in_texture, tex_coord);
}
