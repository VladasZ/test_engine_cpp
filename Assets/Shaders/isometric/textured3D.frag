precision highp float;

in vec2 v_uv;
uniform sampler2D in_texture;
out vec4 color;

void main() {
  color = texture(in_texture, v_uv);
}
