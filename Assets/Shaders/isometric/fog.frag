precision highp float;

uniform vec4 uniform_color;
uniform bool selected;

in vec3 fragment_normal;
in vec3 fragment_position;

out vec4 color;

void main() {

	vec3 light_vector = normalize(vec3(1.0, 1.0, 1.0));

	vec3 ambient = uniform_color.rgb * 0.5;
	vec3 diffuse = uniform_color.rgb * dot(light_vector, fragment_normal);

	color.a = uniform_color.a;
	color.rgb = ambient + diffuse * 0.4;

	float fog_factor = distance(fragment_position / 15.0, vec3(0, 0, 0));

	fog_factor = clamp(fog_factor, 0.0, 1.0);

	color = mix(color, vec4(0.8, 0.8, 0.8, 1.0), fog_factor);

	if (selected)
		color.rgb *= 4.0;
}
