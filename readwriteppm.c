#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

PPM_IMAGE *read_ppm(const char *file_name){
    int width, height, max_colour, Error;
    char p6;
    FILE *file;
    file = fopen(file_name,"r");
    Error = fscanf(file, "%s", &p6);
    Error = fscanf(file, "%d %d", &width, &height);
    Error = fscanf(file, "%d", &max_colour);
    if (!Error)  return NULL;

    PIXEL *A = malloc ((width*height)* sizeof(PIXEL));

    int i = 0;
    while(!feof(file)){
        Error = fscanf(file, "%hhu\n", &(A[i].r));
        Error = fscanf(file, "%hhu\n", &(A[i].g));
        Error = fscanf(file, "%hhu\n", &(A[i].b));
        i++;
    }
    if (!Error)  return NULL;

    PPM_IMAGE *Image = malloc(sizeof(PPM_IMAGE));
    Image->data=A;
    Image->max_color=max_colour;
    Image->width=width;
    Image->height=height;
    fclose(file);
    return Image;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image){
    int width = image->width;

    FILE *file;
    file = fopen(file_name,"w");
    fprintf(file, "P3\n");
    fprintf(file,"%d %d\n", width, image->height);
    fprintf(file,"%d\n", image->max_color);

    for (int i = 0; i < (image->height) ; i++) {
        int t = i * width;
        for (int j = 0; j < (image->width) ; j++) {
            fprintf(file, "%hhu ", (image->data)[t+j].r);
            fprintf(file, "%hhu ", (image->data)[t+j].g);
            fprintf(file, "%hhu ", (image->data)[t+j].b);
        }
        fprintf(file, "\n");
    }
    fclose(file);

}