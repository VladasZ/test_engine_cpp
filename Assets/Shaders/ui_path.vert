layout(location = 0) in vec2 position;

uniform vec2 size;

void main() {

  float x = 2 * (position.x / size.x);
  float y = 2 * (position.y / size.y);
  
  gl_Position = vec4(-1 + x, -1 + y, 1.0, 1.0);
}
