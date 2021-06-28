#include "multithreading.h"

/**
 * bl_ur - entry to blur_image
 * Desc: bl_ur function that applies a Gaussian Blur
 * filter to a single RGB pixel in an img_t image
 * @img: pointer to struct containing original image pixel array
 * @img_blur: pointer to struct containing blurred image pixel array
 * @kernel: pointer to struct containing convolution kernel
 * @px_x: target pixel x coordinate (left to right)
 * @px_y: target pixel y coordinate (top to bottom)
 */
void bl_ur(const img_t *img, img_t *img_blur, const kernel_t *kernel,
	       size_t px_x, size_t px_y)
{
	size_t i, j, k_radius, px_i;
	ssize_t x, y;
	float r_total = 0, g_total = 0, b_total = 0, weight = 0;

	if (!img || !img_blur || !kernel)
		return;

	if (px_x > img->w || px_y > img->h)
		return;

	k_radius = kernel->size / 2;
	for (i = 0, y = (ssize_t)px_y - k_radius; i < kernel->size; i++, y++)
	{
		for (j = 0, x = (ssize_t)px_x - k_radius;
		     j < kernel->size; j++, x++)
		{
			if ((x >= 0 && (size_t)x < img->w) &&
			    (y >= 0 && (size_t)y < img->h))
			{
				weight += kernel->matrix[i][j];
				px_i = (y * img->w) + x;

				r_total += (img->pixels + px_i)->r *
					kernel->matrix[i][j];
				g_total += (img->pixels + px_i)->g *
					kernel->matrix[i][j];
				b_total += (img->pixels + px_i)->b *
					kernel->matrix[i][j];
			}
		}
	}

	px_i = (px_y * img->w) + px_x;
	(img_blur->pixels + px_i)->r = r_total / weight;
	(img_blur->pixels + px_i)->g = g_total / weight;
	(img_blur->pixels + px_i)->b = b_total / weight;
}

/**
 * blur_portion - entry to blu portion
 * Desc: blu_portion function that blurs
 * a portion of an image using a Guassian Blur
 * @portion: pointer to a data structure
 * Return: new blur file created
 */
void blur_portion(blur_portion_t const *portion)
{
	size_t x, y, x_end, y_end;

	if (!portion || !portion->img || !portion->img_blur ||
	    !portion->kernel || !portion->kernel->matrix)
		return;

	if (!portion->w || !portion->h ||
	    !(portion->kernel->size > 1 && portion->kernel->size % 2))
		return;

	y_end = portion->y + portion->h;
	x_end = portion->x + portion->w;
	for (y = portion->y; y < y_end; y++)
		for (x = portion->x; x < x_end; x++)
		{
			bl_ur(portion->img, portion->img_blur,
				  portion->kernel, x, y);
		}
}
