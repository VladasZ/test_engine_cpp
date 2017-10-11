precision highp float;

in vec2 TexCoord;
//in vec3 outColor;

out vec4 color;

uniform sampler2D ourTexture;

void main() {
    
    vec4 fragColor = texture(ourTexture, TexCoord);
    fragColor.a = 1;
    color = fragColor;
}
