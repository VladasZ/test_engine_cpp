layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal  ;
layout(location = 2) in vec4 color   ;

uniform mat4 mvp_matrix    ;
uniform mat4 model_matrix  ;
uniform vec3 light_position;

out vec4 v_color         ;
out vec3 v_light_position;
out vec3 v_normal        ;
out vec3 v_position      ;

void main() {
  
  gl_Position = mvp_matrix * vec4(position, 1.0);
  
  v_color          = color          ;
//  v_light_position = (model_matrix * vec4(light_position, 1.0)).xyz;
//  v_normal         = (model_matrix * vec4(normal,         0.0)).xyz;
  v_light_position = light_position;
  v_normal         = normal        ;
  v_position       = position      ;
}
