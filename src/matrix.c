#include <fract.h>

/**************************************************
 -> two dimensional square matrix data structure <- 
**************************************************/

mat2 mat2_new()
{
    mat2 m;
    int x, y;
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 2; x++) {
            m.data[x][y] = 0.0f;
        }
    }
    return m;
}

mat2 mat2_id()
{
    int i;
    mat2 m = mat2_new();
    for (i = 0; i < 2; i++) {
        m.data[i][i] = 1.0f;
    }
    return m;
}

mat3 mat3_new()
{
    mat3 m;
    int x, y;
    for (y = 0; y < 3; y++) {
        for (x = 0; x < 3; x++) {
            m.data[x][y] = 0.0f;
        }
    }
    return m;
}

mat3 mat3_id()
{
    int i;
    mat3 m = mat3_new();
    for (i = 0; i < 3; i++) {
        m.data[i][i] = 1.0f;
    }
    return m;
}

mat4 mat4_new()
{
    mat4 m;
    int x, y;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            m.data[x][y] = 0.0f;
        }
    }
    return m;
}

mat4 mat4_id()
{
    int i;
    mat4 m = mat4_new();
    for (i = 0; i < 4; i++) {
        m.data[i][i] = 1.0f;
    }
    return m;
}
