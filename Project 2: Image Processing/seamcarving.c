#include <stdlib.h>
#include <stdio.h>
#include "seamcarving.h"
#include <math.h>

int d_y(struct rgb_img *im, int x, int y){
    if (y == 0){
        int r = get_pixel(im, (im->height) - 1, x, 0) - get_pixel(im, 1, x, 0);
        int g = get_pixel(im, (im->height) - 1, x, 1) - get_pixel(im, 1, x, 1);
        int b = get_pixel(im, (im->height) - 1, x, 2) - get_pixel(im, 1, x, 2);
        return (r*r + g*g + b*b);
    }else if (y == (im->height) - 1){
        int r = get_pixel(im, 0, x, 0) - get_pixel(im, y - 1, x, 0);
        int g = get_pixel(im, 0, x, 1) - get_pixel(im, y - 1, x, 1);
        int b = get_pixel(im, 0, x, 2) - get_pixel(im, y - 1, x, 2);        
        return (r*r + g*g + b*b);
    }else{
        int r = get_pixel(im, y + 1, x, 0) - get_pixel(im, y - 1, x, 0);
        int g = get_pixel(im, y + 1, x, 1) - get_pixel(im, y - 1, x, 1);
        int b = get_pixel(im, y + 1, x, 2) - get_pixel(im, y - 1, x, 2);
        return (r*r + g*g + b*b);
    }
}

int d_x(struct rgb_img *im, int x, int y){
    if (x == 0){
        int r = get_pixel(im, y, (im->width) - 1, 0) - get_pixel(im, y, 1, 0);
        int g = get_pixel(im, y, (im->width) - 1, 1) - get_pixel(im, y, 1, 1);
        int b = get_pixel(im, y, (im->width) - 1, 2) - get_pixel(im, y, 1, 2);
        return (r*r + g*g + b*b);
    }else if (x == (im->width) - 1){
        int r = get_pixel(im, y, 0, 0) - get_pixel(im, y, x - 1, 0);
        int g = get_pixel(im, y, 0, 1) - get_pixel(im, y, x - 1, 1);
        int b = get_pixel(im, y, 0, 2) - get_pixel(im, y, x - 1, 2);        
        return (r*r + g*g + b*b);
    }else{
        int r = get_pixel(im, y, x + 1, 0) - get_pixel(im, y, x - 1, 0);
        int g = get_pixel(im, y, x + 1, 1) - get_pixel(im, y, x - 1, 1);
        int b = get_pixel(im, y, x + 1, 2) - get_pixel(im, y, x - 1, 2);
        return (r*r + g*g + b*b);
    }
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    create_img(grad, im->height, im->width);
    int y = 0;
    int x = 0;

    while (y < im->height){
        x = 0;
        while (x < im->width){
            int delta_y = d_y(im, x, y);
            int delta_x = d_x(im, x, y);
            double energy = sqrt((double)delta_x + (double)delta_y)/10;
            int fenergy = (uint8_t)(energy);
            set_pixel(*grad, y, x, fenergy, fenergy, fenergy);
            x++;
        }
        y++;
    }
}

double get_bestArr_pix(double *best_arr, int row, int col, int width){
    return (best_arr)[row * width + col]; 
}

double cmp(double a, double b, double c){
    if(a < b && a < c){
        return a;
    }else if(b < a && b < c){
        return b;
    }else{
    return c;
    }  
}

void dynamic_seam(struct rgb_img *grad, double **best_arr){

    int w = grad->width;

    *best_arr = (double *)malloc(sizeof(double) * (int)(grad->height) * (int)(grad->width));

    for (int i = 0; i < w; i++){
        (*best_arr)[i] = get_pixel(grad, 0, i, 0);
    }

    for (int row = 1; row < grad->height; row++){
        for (int col = 0; col < grad->width; col++){
            double a;
            double b;
            double c;
            if(col == 0){
                a = get_bestArr_pix(*best_arr,row - 1,col,w);
                b = get_bestArr_pix(*best_arr,row - 1,col + 1,w);
                c = 999;
            }
            else if(col == w - 1){
                a = get_bestArr_pix(*best_arr,row - 1,col,w);
                b = get_bestArr_pix(*best_arr,row - 1,col - 1,w);
                c = 999;
            }
            else{
                a = get_bestArr_pix(*best_arr,row - 1,col,w);
                b = get_bestArr_pix(*best_arr,row - 1,col - 1,w);
                c = get_bestArr_pix(*best_arr,row - 1,col + 1,w);
            }
            double energy = get_pixel(grad, row, col, 0);
            (*best_arr)[row * w + col] = energy + cmp(a, b, c);
        }
    }
}

void recover_path(double *best, int height, int width, int **path){
    *path = (int *)malloc(sizeof(int) * height);

    int lastR = height - 1;
    double minVAL = best[lastR * width];
    int minIDX = 0;

    for (int i  = 0; i < width; i++){
        if (best[lastR * width + i] < minVAL){
            minVAL = best[lastR * width + i];
            minIDX = i;
        }
    }

    (*path)[lastR] = minIDX;

    for (int i = lastR - 1; i >= 0; i--){
        int prevCOL = (*path)[i + 1];
        int l = 99999999;
        int r = 99999999;

        int mid = best[i * width + prevCOL];

        if (prevCOL > 0){
            l = best[i * width + prevCOL - 1];
        }
        if (prevCOL < width - 1){
            r = best[i * width + prevCOL + 1];
        }

        if (l <= mid && l <= r){
            (*path)[i] = prevCOL - 1;
        }
        else if(l <= r){
            (*path)[i] = prevCOL;
        }
        else{
            (*path)[i] = prevCOL + 1;
        }
    }
}
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    create_img(dest, src->height, src->width - 1);

    for (int y = 0; y < src->height; y++) {
        int seamX = path[y];
        int destX = 0;

        for (int x = 0; x < src->width; x++) {
            if (x == seamX) {
                continue; 
            }

            uint8_t r = get_pixel(src, y, x, 0);
            uint8_t g = get_pixel(src, y, x, 1);
            uint8_t b = get_pixel(src, y, x, 2);
            set_pixel(*dest, y, destX, r, g, b);

            destX++;
        }
    }
}
