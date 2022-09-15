#include <fract.h>

/********************************************
 -> floating point functions and utilities <- 
********************************************/

float absf(float f)
{
    return (f < 0.0) ? -f : f;
}

float signf(float f)
{
    return (f < 0.0) ? -1.0 : 1.0;
}

float minf(float a, float b)
{
    return (a < b) ? a : b;
}

float maxf(float a, float b)
{
    return (a > b) ? a : b;
}

float clampf(float val, float min, float max)
{
    return maxf(minf(max, val), min);
}

float lerpf(float a, float b, float t)
{
    return a + t * (b - a);
}

float smoothlerpf(float a, float b, float t)
{
    return lerpf(a, b, t * t * (3.0 - 2.0 * t));
}

float ilerpf(float a, float b, float val)
{
    return (b - a != 0.0) ? (val - a) / (b - a) : 0.0;
}

float remapf(float in_a, float in_b, float out_a, float out_b, float val)
{
    return lerpf(out_a, out_b, ilerpf(in_a, in_b, val));
}

float smoothstep(float a, float b, float x) 
{
    x = clampf((x - a) / (b - a), 0.0, 1.0);
    return x * x * (3.0 - 2.0 * x);
}

float isqrtfast(float num) /* Viva Quake forever! */
{
	float x = num * 0.5;
	float y = num;
	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (1.5 - (x * y * y));
    y = y * (1.5 - (x * y * y));
	return y;
}

float isqrtfaster(float num)
{
	float x = num * 0.5;
	float y = num;
	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (1.5 - (x * y * y));
    /* y = y * (1.5 - (x * y * y)); */
	return y;
}

float sqrtfast(float num)
{
    return num * isqrtfast(num);
}

float sqrtfaster(float num)
{
    return num * isqrtfaster(num);
}

/******************************************************
 -> floating point angles and vector transformations <- 
******************************************************/

float rad_to_deg(float rad) 
{
    return rad * (180.0 / M_PI);
}

float deg_to_rad(float deg)
{
    return deg / (180.0 / M_PI);
}

float vec2_to_rad(vec2 v)
{
    return atan2(v.y, v.x);
}

vec2 rad_to_vec2(float rad)
{
    return (vec2){cosf(rad), sinf(rad)};
}

float vec2_2_rad(vec2 v1, vec2 v2)
{
    return atan2(v1.y - v2.y, v1.x - v2.x);
}
