precision highp float;

layout(location = 0) out vec4 color;
in vec2 tex_coord;

uniform sampler2D in_texture;

void main() {
  color = vec4(0, 0, 0, 0.5);//texture(in_texture, tex_coord);
}
