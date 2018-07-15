layout(location = 0) in vec2 position;

uniform mat4 uiTranslation;

void main() {
    gl_Position = uiTranslation * vec4(position, 0.0, 1.0);
}
