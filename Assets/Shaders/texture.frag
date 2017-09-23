precision highp float;

in vec2 TexCoord;
in vec3 outColor;

out vec4 color;

uniform sampler2D ourTexture;

void main() {
    color = texture(ourTexture, TexCoord) * vec4(outColor, 1);
}
