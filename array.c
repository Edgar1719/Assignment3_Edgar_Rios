#include <stdio.h>
#include <stdlib.h>

#include "array.h"

// Outputs all values in the array
void output_array(Array *a) {

    for (int i = 0; i < a->size; i++) {

        printf("%.2f ", a->data[i]);
  
    }
    printf("\n");
}

// Shifts every value one position to the left
void shift_array(Array *a) {

    if (a->size <= 1) {
        return;
    }

    double first = a->data[0];

    for (int i = 0; i < a->size - 1; i++) {

        a->data[i] = a->data[i + 1];
    
    }
    a->data[a->size - 1] = first;
}


// Creates a new array containing averages of adjacent values
Array *average_adjacent(Array *a) {

    Array *new_array = (Array *) malloc(sizeof(Array));

    if (new_array == NULL) {

        return NULL;

    }

    new_array->size = a->size / 2;

    if (new_array->size > 0) {

        new_array->data =
            (double *) malloc(sizeof(double) * new_array->size);

        if (new_array->data == NULL) {
            free(new_array);
            return NULL;
        }
    }
    else {
        new_array->data = NULL;
    }

    for (int i = 0; i < new_array->size; i++) {
        new_array->data[i] =
            (a->data[i * 2] + a->data[i * 2 + 1]) / 2.0;
    }

    return new_array;
}
