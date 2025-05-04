#include "seamcarving.h"
#include "c_img.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct rgb_img *im;
    struct rgb_img *grad;
    double *best_arr;
    int *path;
    struct rgb_img *resized;

    // 1. Read image from .bin file
    read_in_img(&im, "6x5.bin");

    // 2. Compute energy map
    calc_energy(im, &grad);
    printf("Energy map (grayscale values):\n");
    print_grad(grad);

    // 3. Generate cumulative energy table
    dynamic_seam(grad, &best_arr);
    printf("\nBest energy table:\n");
    for (int y = 0; y < grad->height; y++) {
        for (int x = 0; x < grad->width; x++) {
            printf("%6.2f ", best_arr[y * grad->width + x]);
        }
        printf("\n");
    }

    // 4. Recover the lowest energy seam
    recover_path(best_arr, grad->height, grad->width, &path);
    printf("\nSeam path:\n");
    for (int i = 0; i < grad->height; i++) {
        printf("Row %d → col %d\n", i, path[i]);
    }

    // 5. Remove the seam
    remove_seam(im, &resized, path);
    printf("\nResized image:\n");
    print_img(resized);

    // 6. Free memory
    destroy_image(im);
    destroy_image(grad);
    destroy_image(resized);
    free(best_arr);
    free(path);

    return 0;
}
