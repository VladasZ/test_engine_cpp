precision highp float;

in vec4 v_color         ;
in vec3 v_light_position;
in vec3 v_normal        ;
in vec3 v_position      ;

out vec4 color;

void main() {
	vec3 light_vector = normalize(v_light_position - v_position);
	color = v_color;
	vec4 ambient = v_color * 0.2;
	vec3 diffuse = color.rgb * dot(light_vector, v_normal) * (1 / distance(v_position, v_light_position));

	color.a = 1.0;
	color.rgb = color.rgb;// ambient.rgb + diffuse.rgb;

}
