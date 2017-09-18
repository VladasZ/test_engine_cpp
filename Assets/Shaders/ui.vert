layout(location = 0) in vec3 position;

uniform mat4 uniformProjection;

void main() {
    
    gl_Position = uniformProjection * vec4(position, 1.0);
}
