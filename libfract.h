#ifndef LIBFRACT_H
#define LIBFRACT_H

#ifdef __cplusplus
extern "C" {
#endif

/*====================================================
>>>>>>>>>>>>>>  FRACT MATH LIBRARY   >>>>>>>>>>>>>>>>
ANSI C99 header only math library for game-development
fully compatible with OpenGL implementation of vector 
and matrix structures and operations.
=========================================== @eulogic*/

#include <math.h>
#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif
    
typedef struct {
    float x, y;
} vec2;

typedef struct {
    float x, y, z;
} vec3;

typedef struct { 
    float x, y, z, w;
} vec4;

typedef struct { 
    int x, y;
} ivec2;

typedef struct { 
    int x, y, z;
} ivec3;

typedef struct { 
    int x, y, z, w;
} ivec4;

typedef struct { 
    float data[2][2];
} mat2;

typedef struct { 
    float data[3][3];
} mat3;

typedef struct { 
    float data[4][4];
} mat4;

/*
-----------------------------------
 -> Math Utilities and Functions <- 
-----------------------------------
*/

/*********************************************
 -> OS independent pseudo random algorithms <- 
*********************************************/

void rand_seed(unsigned int seed);
unsigned int rand_uint(unsigned int num);
unsigned int rand_num();
unsigned int rand_next();
float randf_norm();

/********************************************
 -> floating point functions and utilities <- 
********************************************/

float signf(float f);
float minf(float a, float b);
float maxf(float a, float b);
float clampf(float val, float min, float max);
float lerpf(float a, float b, float t);
float smooth_lerpf(float a, float b, float t);
float inverse_lerpf(float a, float b, float val);
float remapf(float input_a, float input_b, float out_a, float out_b, float val);
float smoothstep(float a, float b, float x);
float fast_inverse_sqrt(float num);
float fast_sqrt(float num);
float faster_inverse_sqrt(float num);
float faster_sqrt(float num);

/******************************************************
 -> floating point angles and vector transformations <- 
******************************************************/

float rad_to_deg(float rad);
float deg_to_rad(float deg);
float vec2_to_rad(vec2 v);
vec2 rad_to_vec2(float rad);

/**************************************
 -> 2D perlin noise useful functions <- 
**************************************/

float noise2d(float x, float y, int seed);
float perlin2d(float x, float y, float freq, int depth, int seed);

/*
---------------------------------------
 -> Vector Structures and Operations <- 
---------------------------------------
*/

/*******************************************
 -> two dimensional floating point vector <- 
*******************************************/

vec2 vec2_uni(float f);
vec2 vec2_new(float x, float y);
int vec2_cmp(vec2 v1, vec2 v2);
vec2 vec2_add(vec2 v1, vec2 v2);
vec2 vec2_sub(vec2 v1, vec2 v2);
vec2 vec2_neg(vec2 v);
vec2 vec2_mult(vec2 v, float f);
vec2 vec2_div(vec2 v, float f);
float vec2_mag(vec2 v);
float vec2_dist(vec2 v1, vec2 v2);
float vec2_dot(vec2 v1, vec2 v2);
vec2 vec2_cross(vec2 v1, vec2 v2);
vec2 vec2_norm(vec2 v);
vec2 vec2_normf(vec2 v);
void vec2_move(vec2* v, vec2 move);
void vec2_scale(vec2* v, float scale);

vec2 vec2_rotate(vec2 src, float rads);
vec2 vec2_rotate_around(vec2 src, vec2 center, float rads);
vec2 vec2_rotate_and_scale_around(vec2 src, vec2 center, float rads, float scale);
vec2 vec2_scale_around(vec2 src, vec2 center, float scale);

/*********************************************
 -> three dimensional floating point vector <- 
*********************************************/

vec3 vec3_uni(float f);
vec3 vec3_new(float x, float y, float z);
int vec3_cmp(vec3 v1, vec3 v2);
vec3 vec3_add(vec3 v1, vec3 v2);
vec3 vec3_sub(vec3 v1, vec3 v2);
vec3 vec3_neg(vec3 v);
vec3 vec3_mult(vec3 v, float f);
vec3 vec3_div(vec3 v, float f);
float vec3_mag(vec3 v);
float vec3_dist(vec3 v1, vec3 v2);
float vec3_dot(vec3 v1, vec3 v2);
vec3 vec3_cross(vec3 v1, vec3 v2);
vec3 vec3_norm(vec3 v);
vec3 vec3_normf(vec3 v);
void vec3_move(vec3* v, vec3 move);
void vec3_scale(vec3* v, float scale);

/********************************************
 -> four dimensional floating point vector <- 
********************************************/

vec4 vec4_uni(float f);
vec4 vec4_new(float x, float y, float z, float w);
int vec4_cmp(vec4 v1, vec4 v2);
vec4 vec4_add(vec4 v1, vec4 v2);
vec4 vec4_sub(vec4 v1, vec4 v2);
vec4 vec4_neg(vec4 v);
vec4 vec4_mult(vec4 v, float f);
vec4 vec4_div(vec4 v, float f);
float vec4_mag(vec4 v);
float vec4_dist(vec4 v1, vec4 v2);
float vec4_dot(vec4 v1, vec4 v2);
vec4 vec4_cross(vec4 v1, vec4 v2);
vec4 vec4_norm(vec4 v);
vec4 vec4_normf(vec4 v);
void vec4_move(vec4* v, vec4 move);
void vec4_scale(vec4* v, float scale);

/*******************************
 -> integer vector structures <- 
*******************************/

ivec2 ivec2_new(int x, int y);
ivec2 ivec2_uni(int i);
int ivec2_cmp(ivec2 v1, ivec2 v2);

ivec3 ivec3_new(int x, int y, int z);
ivec3 ivec3_uni(int i);
int ivec3_cmp(ivec3 v1, ivec3 v2);

ivec4 ivec4_new(int x, int y, int z, int w);
ivec4 ivec4_uni(float i);
int ivec4_cmp(ivec4 v1, ivec4 v2);

/***********************************************
 -> integer and floating point vector casting <- 
***********************************************/

ivec2 vec2_to_ivec2(vec2 v);
ivec3 vec3_to_ivec3(vec3 v);
ivec4 vec4_to_ivec4(vec4 v);

vec2 ivec2_to_vec2(ivec2 v);
vec3 ivec3_to_vec3(ivec3 v);
vec4 ivec4_to_vec4(ivec4 v);

/*
---------------------------------------
 -> Matrix Structures and Operations <- 
---------------------------------------
*/

/***************************************************
 ->   lightweight stack matrix data structures <- 
***************************************************/

mat2 mat2_new();
mat2 mat2_id();
mat3 mat3_new();
mat3 mat3_id();
mat4 mat4_new();
mat4 mat4_id();

/******************************************
 -> 4x4 matrix functions and operations  <- 
******************************************/

mat4 mat4_translate(mat4 mat, vec3 v);
mat4 mat4_scale(mat4 mat, vec3 v);
mat4 mat4_mult(mat4 m1, mat4 m2);
mat4 mat4_mult_vec4(mat4 mat, vec4 v);
mat4 mat4_mult_vec3(mat4 mat, vec3 v);
mat4 mat4_rot(mat4 mat, float deg, vec3 rot_axis);
mat4 mat4_perspective_RH(float fov, float aspect, float near, float far);
mat4 mat4_perspective_LH(float fov, float aspect, float near, float far);
mat4 mat4_perspective(float fov, float aspect, float near, float far);
mat4 mat4_ortho(float left, float right, float bottom, float top);
mat4 mat4_look_at_LH(vec3 eye_position, vec3 eye_direction, vec3 eye_up);
mat4 mat4_look_at_RH(vec3 eye_position, vec3 eye_direction, vec3 eye_up);
mat4 mat4_look_at(vec3 eye_position, vec3 eye_direction, vec3 eye_up);
mat4 mat4_model(vec3 translation, vec3 scale, vec3 rot_axis, float rot_degs);

/*
-----------------------
 -> Print Data Types <- 
-----------------------
*/

/***************************
 -> formating to stdout   <- 
***************************/

void ivec2_print(ivec2 v);
void ivec3_print(ivec3 v);
void ivec4_print(ivec4 v);
void vec2_print(vec2 v);
void vec3_print(vec3 v);
void vec4_print(vec4 v);
void mat2_print(mat2 m);
void mat3_print(mat3 m);
void mat4_print(mat4 m);

#ifdef __cplusplus
}
#endif
#endif
