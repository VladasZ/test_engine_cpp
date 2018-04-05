layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 uiTranslation;
uniform vec2 uniformPosition;
uniform mat4 transform;

void main() {
    gl_Position = uiTranslation * vec4(position + uniformPosition, 0.0, 1.0);
    TexCoord = texCoord;
}
