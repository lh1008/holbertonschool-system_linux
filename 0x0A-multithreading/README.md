# 0x0A. Multithreading

### Learning Objectives

- What is a thread
- What are the differences between a thread and a process
- What is the difference between Concurrency and Parallelism
- How to create a thread
- How to properly exit a thread
- How to handle mutual execution
- What is a deadlock
- What is a race condition

### Data Structure

```
#include <stddef.h>
#include <stdint.h>

/**
 * struct pixel_s - RGB pixel
 *
 * @r: Red component
 * @g: Green component
 * @b: Blue component
 */
typedef struct pixel_s
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

/**
 * struct img_s - Image
 *
 * @w:      Image width
 * @h:      Image height
 * @pixels: Array of pixels
 */
typedef struct img_s
{
    size_t w;
    size_t h;
    pixel_t *pixels;
} img_t;

/**
 * struct kernel_s - Convolution kernel
 *
 * @size:   Size of the matrix (both width and height)
 * @matrix: Kernel matrix
 */
typedef struct kernel_s
{
    size_t size;
    float **matrix;
} kernel_t;

/**
 * struct blur_portion_s - Information needed to blur a portion of an image
 *
 * @img:      Source image
 * @img_blur: Destination image
 * @x:        X position of the portion in the image
 * @y:        Y position of the portion in the image
 * @w:        Width of the portion
 * @h:        Height of the portion
 * @kernel:   Convolution kernel to use
 */
typedef struct blur_portion_s
{
    img_t const *img;
    img_t *img_blur;
    size_t x;
    size_t y;
    size_t w;
    size_t h;
    kernel_t const *kernel;
} blur_portion_t;
```

### Tasks

_**0. Thread entry point**_
Write a function that will serve as the entry point to a new thread.

_**1. Thread Logger**_
Write a function that uses the `printf` family to print out a given formatted string.

_**2. Blur portion of an image**_
Write a method that blurs a portion of an image using a [Gaussian Blur](https://youtu.be/C_zFhWdM4ic).

_**3. Blur entire image**_
Write a method that blurs the entirety of an image using a [Gaussian Blur](https://youtu.be/C_zFhWdM4ic).

_**4. Thread logger v2**_
Write a function that uses the `printf` family to print out a given formatted string.

_**5. Number to prime factors**_
Write a function that factorizes a number into a list of prime factors.

_**6. Number to prime factors v2**_
The goal of this task is to reproduce the previous task, and to improve it using a thread pool. The tread pool will have for purpose to execute a list of tasks.
