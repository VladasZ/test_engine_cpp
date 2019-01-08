precision highp float;

in vec2 TexCoord;
out vec4 color;

uniform sampler2D ourTexture;

void main() {
    
    vec4 fragmentColor = vec4(1, 1, 1, 1);
    fragmentColor.a = texture(ourTexture, TexCoord).r;
    
    color = fragmentColor;
}
