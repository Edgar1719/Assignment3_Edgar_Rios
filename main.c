#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int main(int argc, char *argv[]) {

    // Confirming user inputs one argument for array size
    if(argc != 2) {

        printf("Incorrect amount of arguments\n");
        return 1;

    }

    // convert command line argument to integer
    int size = atoi(argv[1]);

    //Confirm size is valid
    if(size <= 0) {

        printf("Invalid array size.\n");
        return 1;

    }

    // Dynamically allocate the Array structure (structure itself)
    Array *a = (Array *) malloc(sizeof(Array));

    if(a == NULL) {

        printf("Memory allocation failed.\n");
        return 1;

    }

    a ->size = size;

    // Dynamically allocate the data inside the structure (array itself)
    a ->data = (double *) malloc(sizeof(double) * a->size);

    if(a->data == NULL) {
  
        printf("Memory allocation failed.\n");
        free(a);
        return 1;

    }

    // Use sequential values so shift and averaging results are easier to verify
    for(int i = 0; i < a->size; i++) {

        a->data[i] = i + 1;

    }

    // Output original array
    printf("Original array:\n");
    output_array(a);

    // Shift array
    shift_array(a);

    // Output shifted array
    printf("Shifted array:\n");
    output_array(a);

    // Create new array containing adjacent averages
    Array *averaged = average_adjacent(a);

    if(averaged == NULL) {

        printf("Memory allocation failed.\n");

        free(a->data);
        free(a);

        return 1;

    }

    // Output averaged array
    printf("Adjacent averages:\n");
    output_array(averaged);

    // Free all dynamically allocated memory
    free(averaged->data);
    free(averaged);

    free(a->data);
    free(a);

    return 0;
}
