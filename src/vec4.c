#include <fract.h>

/********************************************
 -> four dimensional floating point vector <- 
********************************************/

vec4 vec4_new(float x, float y, float z, float w)
{
    vec4 ret = {x, y, z, w};
    return ret;
}

vec4 vec4_uni(float f)
{
    vec4 ret = {f, f, f, f};
    return ret;
}

int vec4_cmp(vec4 v1, vec4 v2)
{
    return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w);
}

vec4 vec4_add(vec4 v1, vec4 v2)
{
    vec4 ret = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
    return ret;
}

vec4 vec4_sub(vec4 v1, vec4 v2)
{
    vec4 ret = {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w};
    return ret;
}

vec4 vec4_neg(vec4 v)
{
    vec4 ret = {-v.x, -v.y, -v.z, -v.w};
    return ret;
}

vec4 vec4_mult(vec4 v, float f)
{
    vec4 ret = {v.x * f, v.y * f, v.z * f, v.w * f};
    return ret;
}

vec4 vec4_div(vec4 v, float f)
{
    vec4 ret = {v.x / f, v.y / f, v.z / f, v.w / f};
    return ret;
}

float vec4_sqmag(vec4 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
}

float vec4_mag(vec4 v)
{
    return sqrtfast(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

float vec4_sqdist(vec4 v1, vec4 v2)
{
    vec4 v = _vec4_sub(v1, v2);
    return _vec4_sqmag(v);
}

float vec4_dist(vec4 v1, vec4 v2)
{
    vec4 v = _vec4_sub(v1, v2);
    return _vec4_mag(v);
}

float vec4_dot(vec4 v1, vec4 v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

/* Non standard -- w component is 1.0f (quaterion) */
vec4 vec4_cross(vec4 v1, vec4 v2)
{
    vec3 tmp1 = _vec3_new(v1.x, v1.y, v1.z);
    vec3 tmp2 = _vec3_new(v2.x, v2.y, v2.z);
    vec3 cross = _vec3_cross(tmp1, tmp2);
    vec4 ret = _vec4_new(cross.x, cross.y, cross.z, 1.0f);
    return ret;
}

vec4 vec4_norm(vec4 v)
{
    float d = isqrtfast(_vec4_sqmag(v));
    vec4 ret = {v.x * d, v.y * d, v.z * d, v.w * d};
    return ret;
}

vec4 vec4_normf(vec4 v)
{
    float d = isqrtfaster(_vec4_sqmag(v));
    vec4 ret = {v.x * d, v.y * d, v.z * d, v.w * d};
    return ret;
}

vec4 vec4_normal(vec4 v)
{
    float d = 1.0f / _vec4_mag(v);
    vec4 ret = {v.x * d, v.y * d, v.z * d, v.w * d};
    return ret;
}

vec4 vec4_prod(vec4 a, vec4 b)
{
    vec4 ret = {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
    return ret;
}

vec4 vec4_lerp(vec4 a, vec4 b, float t)
{
    vec4 ret = {_lerpf(a.x, b.x, t), _lerpf(a.y, b.y, t), _lerpf(a.z, b.z, t), _lerpf(a.w, b.w, t)};
    return ret;
}

void vec4_move(vec4* v, vec4 move)
{
    v->x += move.x;
    v->y += move.y;
    v->z += move.z;
    v->w += move.z;
}

void vec4_scale(vec4* v, float scale)
{
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;
    v->w *= scale;
}
