
mat4 rotation_x(in float angle) {
    float cos_x = cos(angle);
    float sin_x = sin(angle);
    return mat4 (
        1,      0,     0, 0,
        0,  cos_x, sin_x, 0,
        0, -sin_x, cos_x, 0,
        0,      0,     0, 1
    );
}

mat4 rotation_y(in float angle) {
    float cos_y = cos(angle);
    float sin_y = sin(angle);
    return mat4 (
        cos_y, 0, -sin_y, 0,
            0, 1,      0, 0,
        sin_y, 0,  cos_y, 0,
            0, 0,      0, 1
    );
}

mat4 rotation_z(in float angle) {
    float cos_z = cos(angle);
    float sin_z = sin(angle);
    return mat4 (
        cos_z, sin_z, 0, 0,
       -sin_z, cos_z, 0, 0,
            0,     0, 1, 0,
            0,     0, 0, 1
    );
}