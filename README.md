## x86-to-C-interfacing
Seperidad, Abigail

Cataluña, Jorice Erika

LBYARCH - S13

## Short Video Demo
[Click here to watch the demo](https://drive.google.com/file/d/14D1VlDNHVTRta-IJR7Bsu83JuvQsx7bM/view?usp=sharing) or access this link: https://drive.google.com/file/d/14D1VlDNHVTRta-IJR7Bsu83JuvQsx7bM/view?usp=sharing

## Performance Results
### (10x10)
Execution Time of C: 0.000000 msec

Execution Time of x86: 0.000000 msec

Time Difference: 0.000000 msec

### (100x100)
Execution Time of C: 0.457143 msec

Execution Time of x86: 0.028571 msec

Time Difference: 0.428571 msec

### (1000x1000)
Execution Time of C: 41.657143 msec

Execution Time of x86: 1.257143 msec

Time Difference: 40.400000 msec

### Short Analysis
During 10x10, the input was too low that the speed of the computation was negligible enough by the system, thus the 0.00 msec for both C and x86. However, the speed of x86 assembly is evidently faster than C if the input reaches 1 000 000 and above. This makes x86 more efficient if the dataset is huge.

## Screenshot of Program Output with Correctness Check
### (3 x 4 specs)
![image](https://github.com/user-attachments/assets/2acbbf00-b3ba-4b25-8718-296ab5e0fa2d)

### (10 x 10)
![image](https://github.com/user-attachments/assets/6abb2828-f599-4f13-bc0d-aee58055209f)

### (100 x 100)
![image](https://github.com/user-attachments/assets/5dc0bde0-13fd-445c-a2e8-e5ca8d834b73)

### (1000 x 1000)
![image](https://github.com/user-attachments/assets/10c02710-4c05-46fc-90f4-3748ccf25e0a)
