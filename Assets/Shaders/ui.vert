layout(location = 0) in vec2 position;

uniform mat4 uniformProjection;

void main() {
    
    gl_Position = uniformProjection * vec4(position, 0.0, 1.0);
}
