#include <fract.h>

/*******************************************
 -> two dimensional floating point vector <- 
*******************************************/

vec2 vec2_new(float x, float y)
{
    vec2 ret = {x, y};
    return ret;
}

vec2 vec2_uni(float f)
{
    vec2 ret = {f, f};
    return ret;
}

int vec2_cmp(vec2 v1, vec2 v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}

vec2 vec2_add(vec2 v1, vec2 v2)
{
    vec2 ret = {v1.x + v2.x, v1.y + v2.y};
    return ret;
}

vec2 vec2_sub(vec2 v1, vec2 v2)
{
    vec2 ret = {v1.x - v2.x, v1.y - v2.y};
    return ret;
}

vec2 vec2_neg(vec2 v)
{
    vec2 ret = {-v.x, -v.y};
    return ret;
}

vec2 vec2_mult(vec2 v, float f)
{
    vec2 ret = {v.x * f, v.y * f};
    return ret;
}

vec2 vec2_div(vec2 v, float f)
{
    vec2 ret = {v.x / f, v.y / f};
    return ret;
}

float vec2_sqmag(vec2 v)
{
    return v.x * v.x + v.y * v.y;
}

float vec2_mag(vec2 v)
{
    return sqrtfast(v.x * v.x + v.y * v.y);
}

float vec2_sqdist(vec2 v1, vec2 v2)
{
    vec2 v = _vec2_sub(v1, v2);
    return _vec2_sqmag(v);
}

float vec2_dist(vec2 v1, vec2 v2)
{
    vec2 v = _vec2_sub(v1, v2);
    return _vec2_mag(v);
}

float vec2_dot(vec2 v1, vec2 v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

/* 2D cross product is not defined: perpendicular difference instead */
vec2 vec2_cross(vec2 v1, vec2 v2)
{
    vec2 ret = {-(v1.y - v2.y), v1.x - v2.x};
    return ret;
}

vec2 vec2_norm(vec2 v)
{
    float d = isqrtfast(_vec2_sqmag(v));
    vec2 ret = {v.x * d, v.y * d};
    return ret;
}

vec2 vec2_normf(vec2 v)
{
    float d = isqrtfaster(_vec2_sqmag(v));
    vec2 ret = {v.x * d, v.y * d};
    return ret;
}

vec2 vec2_normal(vec2 v)
{
    float d = 1.0f / _vec2_mag(v);
    vec2 ret = {v.x * d, v.y * d};
    return ret;
}

vec2 vec2_prod(vec2 a, vec2 b)
{
    vec2 ret = {a.x * b.x, a.y * b.y};
    return ret; 
}

vec2 vec2_lerp(vec2 a, vec2 b, float t)
{
    vec2 ret = {_lerpf(a.x, b.x, t), _lerpf(a.y, b.y, t)};
    return ret;
}

void vec2_move(vec2* v, vec2 move)
{
    v->x += move.x;
    v->y += move.y;
}

void vec2_scale(vec2* v, float scale)
{
    v->x *= scale;
    v->y *= scale;
}

vec2 vec2_rotate(vec2 src, float rads)
{
    float r = vec2_to_rad(src) + rads;
    return vec2_mult(rad2vec2(r), vec2_mag(src));
}

vec2 vec2_rotate_around(vec2 src, vec2 center, float rads)
{
    vec2 v = _vec2_sub(src, center);
    float r = vec2_to_rad(v) + rads;
    return vec2_add(center, vec2_mult(rad2vec2(r), vec2_mag(v)));
}

vec2 vec2_scale_around(vec2 src, vec2 center, float scale)
{
    vec2 v = _vec2_sub(src, center);
    float r = vec2_to_rad(v);
    return vec2_add(center, vec2_mult(rad2vec2(r), vec2_mag(v) * scale));
}

vec2 vec2_rotate_and_scale_around(vec2 src, vec2 center, float rads, float scale)
{
    vec2 v = _vec2_sub(src, center);
    float r = vec2_to_rad(v) + rads;
    return vec2_add(center, vec2_mult(rad2vec2(r), vec2_mag(v) * scale));
}
