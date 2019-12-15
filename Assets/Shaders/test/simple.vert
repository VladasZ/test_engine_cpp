
#define IN attribute
#define OUT varying

// #define IN in
// #define OUT out

IN vec4 vPosition;

void main() {
 gl_Position = vPosition;
}
