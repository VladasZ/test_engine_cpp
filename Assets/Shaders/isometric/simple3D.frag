precision highp float;

uniform vec4 uniform_color;
uniform bool selected;

out vec4 color;

void main() {

  color = uniform_color;

  if (selected) {
    color.rgb *= 4.0;
  }
}
