
mat4 rotation_matrix(in float angle) {
    float cos_z = cos(angle);
    float sin_z = sin(angle);
    return mat4 (
        cos_z, sin_z, 0, 0,
       -sin_z, cos_z, 0, 0,
            0,     0, 1, 0,
            0,     0, 0, 1
    );
}

