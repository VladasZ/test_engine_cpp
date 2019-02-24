layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 mvp_matrix;

out vec4 v_color;

void main() {
  gl_Position = mvp_matrix * vec4(position, 1.0);
  v_color = color;
}
