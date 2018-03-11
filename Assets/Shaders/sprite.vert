layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 uniformProjection;
uniform vec2 uniformPosition;

void main() {
    gl_Position = uniformProjection * vec4(position + uniformPosition, 0.0, 1.0);
    TexCoord = texCoord;
}
