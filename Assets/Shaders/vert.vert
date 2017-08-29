layout(location = 0) in vec3 position;
layout(location = 1) in vec4 vertexColor;

uniform vec4 dominatingColor;
uniform float yFlip;

uniform mat4 transformMatrix;

out vec4 theColor;

void main() {
    
    vec4 v = vec4(position, 1.0);
    gl_Position = transformMatrix * v;
    
    theColor = vertexColor;
}
