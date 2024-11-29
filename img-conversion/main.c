#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void imgCvtGrayDoubleToInt(int rows, int cols, double** dbl_img_arr, int** int_img_arr);

void imgCvtGrayDoubleToIntInC(int rows, int cols, double** dbl_img_arr, int** int_img_arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int_img_arr[i][j] = (int)(round(dbl_img_arr[i][j] * 255.0)); // compute then cast to an int for it to match the datatype
        }
    }
}

int main() {
    // declare the variables for the array size
    int rows, cols;

    // declare timer
	clock_t start, end;
	double time_taken;

    // read the array size input
    scanf_s("%d %d", &rows, &cols);

    /*************************** IN C ***************************/

    // dynamically allocate memory for the double (input) array
    double** dbl_img_arr = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        dbl_img_arr[i] = (double*)malloc(cols * sizeof(double));
    }

    // dynamically allocate memory for the integer (output) array
    int** int_img_arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        int_img_arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // store the inputs in the double array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf_s("%lf", &dbl_img_arr[i][j]);
        }
    }

    // temporary init in the integer array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int_img_arr[i][j] = 0;
        }
    }

    printf("\n"); // spacer
    printf("Double Pixel Values:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf ", dbl_img_arr[i][j]);
        }
        printf("\n");
    }

    // time the function
    start = clock();
    imgCvtGrayDoubleToIntInC(rows, cols, dbl_img_arr, int_img_arr); // conversion in c
    end = clock();

    time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("\n"); // spacer
    printf("img conversion from double to int using c took: %lf msec\n", time_taken);

    // compute and print the converted values
    printf("Converted Integer Pixel Values in C:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", int_img_arr[i][j]);
        }
        printf("\n");
    }
    /*************************** END C ***************************/

    /*************************** IN ASSEMBLY ***************************/

    // temporary re-init in the integer array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int_img_arr[i][j] = 0;
        }
    }

    // time the function
    start = clock();
    imgCvtGrayDoubleToInt(rows, cols, dbl_img_arr, int_img_arr); // assembly function here
    end = clock();

    time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("\n"); // spacer
    printf("img conversion from double to int using assembly took: %lf msec\n", time_taken);

    // compute and print the converted values
    printf("Converted Integer Pixel Values in x86-64:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", int_img_arr[i][j]);
        }
        printf("\n");
    }

    /*************************** END ASSEMBLY ***************************/

    return 0;
}