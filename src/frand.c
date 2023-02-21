#include <fract.h>
#include <limits.h>

/*********************************************
 -> OS independent pseudo random algorithms <- 
*********************************************/

static unsigned int fseed = 0;

void frand_seed_set(unsigned int n) 
{
    fseed = n;
}

unsigned int frand_seed_get(void)
{
    return fseed;
}

unsigned int frand_hash(unsigned int num)
{
    num = (num << 13) ^ num;
    return ((num * (num * num * 15731 + 789221) + 1376312589) & 0x7fffffff);
}

unsigned int frand_uint(void)
{
    return frand_hash(fseed++);
}

float frand_norm(void)
{
    return (float)frand_hash(fseed++) / (float)INT_MAX;
}

float frand_signed(void)
{
    return 2.0 * ((float)frand_hash(fseed++) / (float)INT_MAX) - 1.0;
}

