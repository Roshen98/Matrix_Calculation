# Matrix_Calculation

Implemented 4 versions of a matrix program and wrote a driver to test 3 different operations with matrices. The matrix operations included are Addition, Subtraction and Multiplication. The driver is simple as like asking the user to enter two matrices and then presenting a simple menu that allows the user to select the operation they want to test. 

The menu is in a loop so that the user can test any other operation unless they choose to exit the menu. There is an option to select two new matrices. The result of every operation is printed out after the operation is chosen. The matrices hold float values; float data types are in all versions. Also, the program checks based on sizes of the matrices if the chosen operation is permissible on the two matrices entered by the user. The matrices can be entered by the user by first entering the size of each matrix followed by the element. 


The four versions are as follows:


1. C/C++ version that uses a regular stack dynamic 2D array for representing the matrices.The size of array is 100x100. Appropriate functions are made to do the operations of addition, subtraction and multiplication of two matrices.


2. C/C++ version that uses a pointer to a pointer (**p) that is allocated memory using new or malloc to create the 2D matrices. 3 functions are provided: one for addition, subtraction and multiplication respectively. This version takes in the two matrices and return the result back (as a new matrix which is also declared as a pointer to a pointer).


3. C/C++ version that uses a pointer to a pointer as a private data in a class called matrix and overloaded operator functions (+ for addition, - for subtraction and * for multiplication) are created to the class for doing the matrix operations. Other appropriate member functions, like constructors, destructors and any other helper functions are included.


4.Java Class version called matrix and use arrays as well as appropriate methods for the matrix operations.


The multiplication function of each version by multiplying the same two matrices (say of size 10x10) are commented on the time taken to do the multiplication.

Comments are on the time taken by version 2,3 and 4 to complete the multiplication operation as the size of matrices increases. A table and a graph of time taken to complete as a function of matrix size (using square matrices for this comparison should be fine) are shown in the pdf for reference.
