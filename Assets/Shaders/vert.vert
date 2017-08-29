layout(location = 0) in vec3 position;
layout(location = 1) in vec4 vertexColor;

out vec4 theColor;

void main() {
    
    gl_Position = vec4(position, 1.0);
    
    theColor = vertexColor;
}
