#include "multithreading.h"

/**
 * create_portions - entry to create portions
 * Desc: create_portions function to check the image
 * @img_blur: copy of the image which needs to be blurred
 * @img: image which needs to be blurred
 * @kernel: kernel matrix (Gaussian Blur)
 * Return: initialized portions array or NULL if failed
*/
blur_portion_t *create_portions(img_t *img_blur, img_t const *img,
				kernel_t const *kernel)
{
	blur_portion_t *portions;
	int i;
	size_t step, width;

	portions = malloc(sizeof(*portions) * NUM_THREADS);
	if (!portions)
		return (NULL);
	width = img->w / NUM_THREADS;
	for (i = 0, step = 0; i < NUM_THREADS; ++i, step += width)
	{
		portions[i].kernel = kernel;
		portions[i].img = img;
		portions[i].img_blur = img_blur;
		portions[i].h = img->h;
		portions[i].y = 0;
		portions[i].x = step;
		portions[i].w = img->w / NUM_THREADS;
		if (i == NUM_THREADS - 1)
			portions[i].w += img->w % NUM_THREADS;
	}
	return (portions);
}

/**
 * thread_entry - entry to thread_entry
 * Desc: thread_entry function
 * @param: portion of the img which needs to be blurred
 * Return: nothing, void function or NULL if portions empty
*/
void *thread_entry(void *portions)
{
	if (!portions)
		pthread_exit(NULL);

	blur_portion((blur_portion_t *)portions);
	pthread_exit(NULL);
}

/**
 * blur_image - entry to blur image
 * Desc: blur_image function that blurs an
 * entirety of an image using threads
 * @img_blur: copy of the image which needs to be blurred
 * @img: image which needs to be blurred
 * @kernel: kernel matrix (Gaussian Blur)
 * Return: nothing, void function
*/
void blur_image(img_t *img_blur, img_t const *img, kernel_t const *kernel)
{
	blur_portion_t *portions;
	int i;
	pthread_t tids[NUM_THREADS];

	portions = create_portions(img_blur, img, kernel);
	if (!portions)
		return;
	for (i = 0; i < NUM_THREADS; ++i)
		pthread_create(&tids[i], NULL, &thread_entry, &portions[i]);
	for (i = 0; i < NUM_THREADS; ++i)
		pthread_join(tids[i], NULL);
	free(portions);
}
