// Liangjie Shen
#include <iostream>
#include <time.h>      // import time  
using namespace std;

void addMatrix(float matrixA[][100],float matrixB[][100],int rowA,int rowB,int colA,int colB){
    // function to add the two matrices
    float matrixResult[rowA][colA];
    if(rowA == rowB && colA == colB){
        // if the number of rows and columns are the same 
        for(int i = 0; i < rowA; i++){
            for(int j = 0; j < colB; j++){
                matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
        // print the resulting matrix
        for(int i = 0; i < rowA; i++){
            for(int j = 0; j < colA; j++){
                cout << matrixResult[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    else{
        cout << "The two matrix cannot be added" << endl;
    }
}

void subtractMatrix(float matrixA[][100],float matrixB[][100],int rowA,int rowB,int colA,int colB){
    // function to subtract the two matrices
    float matrixResult[rowA][colA];
    if(rowA == rowB && colA == colB){
        // if the number of rows and columns are the same 
        for(int i = 0; i < rowA; i++){
            for(int j = 0; j < colB; j++){
                matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }
        // print the resulting matrix
        for(int i = 0; i < rowA; i++){
            for(int j = 0; j < colA; j++){
                cout << matrixResult[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    else{
        cout << "The two matrix cannot be subtracted" << endl;
    }
}

void multiplyMatrix(float matrixA[][100],float matrixB[][100],int rowA,int rowB,int colA,int colB){
    // function to multiply the two matrices
    float matrixResult[rowA][colB];
    if(colA == rowB){
        // if the number of columns in the first matrix equals to the number 
        // of rows in the second matrix
        clock_t start = clock (); // start time
        for(int i = 0; i < rowA; i++){
            for(int j = 0; j < colB; j++){
                matrixResult[i][j] = 0;
                for(int k = 0; k < colA; k++){
                    matrixResult[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        // stop time and calculate the time taken 
        cout << "Time Taken for Multiplication: " << 
            (((float)( clock() - start )) / CLOCKS_PER_SEC)*1000000000 << " nano seconds." << endl;
        // print the resulting matrix
        for(int i = 0; i < rowA; i++){
            for(int j = 0; j < colB; j++){
                cout << matrixResult[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    else{
        cout << "The two matrix cannot be multiplied" << endl;
    }
}

int main()
{
    const int SIZE = 100;
    int rowA = 0, colA = 0, rowB = 0, colB = 0; 
    float matrixA[SIZE][SIZE], matrixB[SIZE][SIZE]; // Limit the size of array to 100x100
    char option;

    cout << "Welcome to the matrix world!" << endl;
    
    while(rowA < 1 || colA < 1){
        cout << "Please enter the number of rows and columns of the first matrix[>0]: " << endl;
        
        cout << "row: ";
        cin >> rowA;
        cout << "column: ";
        cin >> colA;
        
        if(rowA < 1 || colA < 1)
            cout << "Invalid input!" << endl;
    }
    
    cout << "Please enter the first matrix: " << endl;
    for(int i = 0; i < rowA; i++){
        for(int j = 0; j < colA; j++){
            cin >> matrixA[i][j];
        }
    }
    
    while(rowB < 1 || colB < 1){
        cout << "Please enter the number of rows and columns of the second matrix[>0]: " << endl;
        cout << "row: ";
        cin >> rowB;
        cout << "column: ";
        cin >> colB;
        
        if(rowB < 1 || colB < 1)
            cout << "Invalid input!" << endl;
    }
    
    cout << "Please enter the second matrix: " << endl;
    for(int i = 0; i < rowB; i++){
        for(int j = 0; j < colB; j++){
            cin >> matrixB[i][j];
        }
    }
    
    cout << endl;
    
    while(true){
        cout << "What do you wish to do?(Enter A, S, M, N or E)" << endl;
        cout << "A : Addition" << endl;
        cout << "S : Subtraction" << endl;
        cout << "M : Multiplication" << endl;
        cout << "N : New Matrix" << endl;
        cout << "E : Exit" << endl;
        cin >> option;
        cout << endl;
        
        if(option == 'A' or option == 'a'){
            addMatrix(matrixA,matrixB,rowA,rowB,colA,colB);
        }
        
        else if(option == 'S' or option == 's'){
            subtractMatrix(matrixA,matrixB,rowA,rowB,colA,colB);
        }
        
        else if(option == 'M' or option == 'm'){
            
            multiplyMatrix(matrixA,matrixB,rowA,rowB,colA,colB);
            
            cout <<endl;
        }
        
        else if(option == 'N' or option == 'n'){
            cout << "Please enter the number of rows and columns of the first matrix: " << endl;
            cout << "row: ";
            cin >> rowA;
            cout << "column: ";
            cin >> colA;
            
            cout << "Please enter the first matrix: " << endl;
            for(int i = 0; i < rowA; i++){
                for(int j = 0; j < colA; j++){
                    cin >> matrixA[i][j];
                }
            }
            
            cout << "Please enter the number of rows and columns of the second matrix: " << endl;
            cout << "row: ";
            cin >> rowB;
            cout << "column: ";
            cin >> colB;
            
            cout << "Please enter the second matrix: " << endl;
            for(int i = 0; i < rowB; i++){
                for(int j = 0; j < colB; j++){
                    cin >> matrixB[i][j];
                }
            }
            
            cout << endl;
        }
        
        else if(option == 'E' or option == 'e'){
            break;
        }
        
        else{
            cout << endl;
            cout << "wrong option please try again!" << endl;
        }
    }
}
