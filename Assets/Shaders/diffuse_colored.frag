precision highp float;

in vec4 v_color         ;
in vec3 v_light_position;
in vec3 v_normal        ;
in vec3 v_position      ;

out vec4 color;

void main() {
	vec3 light_vector = normalize(v_light_position - v_position);
	color = v_color * dot(light_vector, v_normal);
	color.g = v_color.g * 0.1f;
	//color = v_color;
	//color.a = 0.1;
	//color.r = 1;//dot(light_vector, v_normal);
}
