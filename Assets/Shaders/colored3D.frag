precision highp float;

in vec4 v_color;
out vec4 color;

void main() {

  vec4 result_color = v_color;
  result_color.a = 0.5;
  color = result_color;
}
