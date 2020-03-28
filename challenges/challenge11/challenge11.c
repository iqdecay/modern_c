#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image/stb_image_write.h"

unsigned char **create2DArray(int width, int height) {
  unsigned char *values = calloc(height * width, sizeof(unsigned char));
  unsigned char **rows = malloc(height * sizeof(unsigned char *));
  for (int i = 0; i < height; ++i) {
    rows[i] = values + i * width;
  }
  return rows;
}

unsigned char *create1DArray(int length) {
  unsigned char *values = calloc(length, sizeof(unsigned char));
  return values;
}

void destroyArray(unsigned char **arr) {
  free(*arr);
  free(arr);
}

unsigned char *flattenArray(unsigned char **arr, int width, int height) {
  unsigned char *flattened = create1DArray(width * height);
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      flattened[i * width + j] = arr[i][j];
    }
  }
  return flattened;
}


int main(void) {
  int width, height, channels;
  unsigned char *color_image = stbi_load("lena_color.png", &width, &height, &channels, 0);
  size_t img_size = width * height * channels;
  int gray_channels = channels == 4 ? 2 : 1;
  unsigned char *gray_image;
  int gray_size = gray_channels * width * height;
  gray_image = malloc(gray_size);
  if (gray_image == NULL) {
    printf("Unable to allocate memory for gray_image");
    exit(1);
  }
  unsigned char pixel, pr, pg, pb, t;
  for (int i = 0; i < width * height; i += 1) {
    pr = *(color_image + channels * i);
    pg = *(color_image + channels * i + 1);
    pb = *(color_image + channels * i + 2);
    pixel = (pr) / 3;
    *(gray_image + gray_channels*i) = pixel;
    if (channels == 4) {
      t = *(color_image + channels * i + 3);
      *(gray_image + gray_channels*i +1) = t;
    }
  }
  printf("Image has supposedly been grayscaled");
  printf("Size is %d\n", sizeof(gray_image));
  stbi_write_png("lena_gray.png", width, height, gray_channels, gray_image, width * gray_channels);
  free(gray_image);
  free(color_image);
  printf("Size is %d\n", sizeof(gray_image));



}

