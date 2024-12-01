//Seperidad, Abigail
//Cataluña, Jorice Erika
//S13

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

extern void imgCvtGrayDoubleToInt(int rows, int cols, double** dbl_img_arr, int** x86_int_img_arr);

void imgCvtGrayDoubleToIntInC(int rows, int cols, double** dbl_img_arr, int** c_int_img_arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c_int_img_arr[i][j] = (int)round(dbl_img_arr[i][j] * 255.0); // compute then cast to an int for it to match the datatype
        }
    }
}

int main() {
    // declare the variables for the array size and # of executions
    int rows, cols, i, j;
    int exec_times = 35;
    bool same = true, n_rows_check = false, n_cols_check = false, last_num_correct = false;

    // declare timer
	clock_t start, end;
	double time_taken = 0.0;
    int flag = 0;

    // read the array size input
    scanf_s("%d %d", &rows, &cols);
    if (rows < 0 || cols < 0) {
        printf("Please input between positive integers only.\n");
        return 1;
    }

    /*************************** IN C ***************************/

    // dynamically allocate memory for the double (input) array
    double** dbl_img_arr = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        dbl_img_arr[i] = (double*)malloc(cols * sizeof(double));
    }

    // dynamically allocate memory for the x86 integer (output) array
    int** x86_int_img_arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        x86_int_img_arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // dynamically allocate memory for the C integer (output) array
    int** c_int_img_arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        c_int_img_arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // store the inputs in the double array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf_s("%lf", &dbl_img_arr[i][j]);
            if (dbl_img_arr[i][j] <= 0.0 || dbl_img_arr[i][j] >= 1.0) {
                printf("Please input between 0-1 only.\n");
                return 1;
            }
        }
    }

    // temporary init in the C and x86 integer arrays
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c_int_img_arr[i][j] = 0;
            x86_int_img_arr[i][j] = 0;
        }
    }

    // test the function 35 times
    double c_avg_time_taken = 0.0;
    for (int i = 0; i < exec_times; i++) {
        // time the function
        start = clock();
        imgCvtGrayDoubleToIntInC(rows, cols, dbl_img_arr, c_int_img_arr); // conversion in c
        end = clock();
        time_taken = (double)(end-start) * 1000.0 / (double)CLOCKS_PER_SEC;

        // get the average execution time for ASSEMBLY
        if (i > 0) { // discarding the first loop
            c_avg_time_taken += time_taken;
        }
    }
        printf("\n"); // spacer

        // compute and print the converted values
        printf("Converted Integer Pixel Values in C:\n");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                printf("%d ", c_int_img_arr[i][j]);
                if (j == cols) {
                    printf("Col %d: ", j);
                }
            }
            printf("\n");
        }
    c_avg_time_taken /= (exec_times * 1.0);

    /*************************** END C ***************************/

    /*************************** IN ASSEMBLY ***************************/

    // test the function 35 times
    double x86_avg_time_taken = 0;
    for (int i = 0; i < exec_times; i++) {
        // time the function
        start = clock();
        imgCvtGrayDoubleToInt(rows, cols, dbl_img_arr, x86_int_img_arr); // assembly function here
        end = clock();

        time_taken = ((double)(end-start)) * 1000.0 / CLOCKS_PER_SEC;
        //printf("Time Taken in x86: %lf\n", time_taken);

        // get the average exdcution time for ASSEMBLY
        if (i > 0) { // discarding the first loop
            x86_avg_time_taken += time_taken;
        }
    }
        printf("\n"); // spacer

        // compute and print the converted values
        printf("Converted Integer Pixel Values in x86-64:\n");
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                printf("%d ", x86_int_img_arr[i][j]);
            }
            printf("\n");
        }
    x86_avg_time_taken /= (exec_times * 1.0);

    /*************************** END ASSEMBLY ***************************/

    printf("\n============ ANALYSIS CHECK ============\n");
    //comparing C and Assembly outputs:
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (x86_int_img_arr[i][j] != c_int_img_arr[i][j]) {
                same = false;
                printf("%d\n", x86_int_img_arr[i][j]);
                printf("%d\n", c_int_img_arr[i][j]);

            }
        }
    }
    printf("Are C and Assembly array output the same?: %d\n", same);
    printf("# of times the input was tested: %d\n", exec_times);
    printf("Average Execution Time for C: %lf msec\n", c_avg_time_taken);
    printf("Average Execution Time for x86: %lf msec\n", x86_avg_time_taken);
    printf("Time Difference of C and x86: %lf msec\n", c_avg_time_taken - x86_avg_time_taken);

    return 0;
}