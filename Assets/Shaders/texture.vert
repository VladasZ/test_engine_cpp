layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
//layout (location = 1) in vec3 inColor;

out vec2 TexCoord;
//out vec3 outColor;

void main() {
    gl_Position = vec4(position, 1.0f);
    //outColor = inColor;
    TexCoord = texCoord;
}
