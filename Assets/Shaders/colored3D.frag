precision highp float;

uniform vec4 uniform_color;

in vec3 fragment_normal;

out vec4 color;

void main() {
  
  vec3 light_vector = normalize(vec3(1, 1, 1));
  
  vec3 ambient = uniform_color.rgb * 0.5;
  vec3 diffuse = uniform_color.rgb * dot(light_vector, fragment_normal);

  color.a = uniform_color.a;
  color.rgb = ambient + diffuse * 0.4;
}
