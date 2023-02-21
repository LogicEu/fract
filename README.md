# fract

> Small math library for game and graphics written in C99. Fully
> compatible with OpenGL. Some of the features of the library are: 

* Pseudo Random Number Generator
* 2D Perlin Noise 
* Floating Point Vectors (2D, 3D, and 4D)
* 4x4 Matrix Operations (Projections, Rotations, etc...)
* Lerp, Smoothlerp, Sqrtfast, Clamp, etc...

> Fract has a single header file fract.h that includes all declarations. The only
> dependency of fract is the standard math library, used mainly for
> trigonometry.

## Example

```C

#include <fract.h>

int main()
{
    int width = 800;
    int height = 600;

    float aspect = (float)width / (float)height;
    float near = 0.01F;
    float far = 1000.0F;
    float fov = deg2rad(45.0F);

    vec3 position = {0.0F, 0.0F, 0.0F};
    vec3 direction = {0.0F, 0.0F, 1.0F};
    vec3 up = {0.0F, 1.0F, 0.0F};

    mat4 projection = mat4_perspective(fov, aspect, near, far);
    mat4 view = mat4_look_at(position, direction, up);
    mat4 model = mat4_id();
    mat4 mvp = mat4_mult(projection, mat4_mult(view, model));

    /* ... */
    
    glUniformMatrix4fv(uniform, 1, GL_FALSE, &mvp.data[0][0]);

    /* ... */
}

```

## Build

> There are two build scripts in this repository, one is a Makefile and the
> other a shell script. You can compile the library with any of the two.
> The build scripts currently work on Linux and MacOS.

```shell
make all -j # or ./build.sh all
```
> There is a simple installation function that builds the
> library and puts it in the /usr/local directory:

```shell
sudo make install # or sudo ./build.sh install
```

> Clean object files and binaries created during compilation in /tmp 
> and /bin with:

```shell
make clean # or ./build.sh clean
```

