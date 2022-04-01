// Liangjie Shen
#include <iostream>
#include <time.h>       // import time
using namespace std;

float **addMatrix(float **matrixA,float **matrixB,int rowA,int rowB,int colA,int colB){
    // function to add the two matrices and return the result
    float **matrixResult = new float * [rowA];
    
    for(int i = 0; i < rowA; i++){
        matrixResult[i] = new float[colA];
        for(int j = 0; j < colA; j++){
            *(*(matrixResult+i)+j) = *(*(matrixA+i)+j) + *(*(matrixB+i)+j);
            
        }
    }
    return matrixResult;
  
}

float **subtractMatrix(float **matrixA,float **matrixB,int rowA,int rowB,int colA,int colB){
    // function to subtract the two matrices and return the result
    float **matrixResult = new float * [rowA];
    
    for(int i = 0; i < rowA; i++){
        matrixResult[i] = new float[colA];
        for(int j = 0; j < colA; j++){
            *(*(matrixResult+i)+j) = *(*(matrixA+i)+j) - *(*(matrixB+i)+j);
            
        }
    }
    return matrixResult;
  
}

float **multiplyMatrix(float **matrixA,float **matrixB,int rowA,int rowB,int colA,int colB){
    // function to multiply the two matrices and return the result
    float **matrixResult = new float * [rowA];
    clock_t start = clock (); // time start
    for(int i = 0; i < rowA; i++){
        matrixResult[i] = new float[colA];
        for(int j = 0; j < colB; j++){
            *(*(matrixResult+i)+j) = 0;
            for(int k = 0; k < colA; k++){
                *(*(matrixResult+i)+j) += *(*(matrixA+i)+k) * *(*(matrixB+k)+j);
            }
            
        }
    }
    // time stops and calculate the time taken
    cout << "Time Taken for Multiplication: " << 
            (((float)( clock() - start )) / CLOCKS_PER_SEC)*1000000000 << " nano seconds." << endl;
    return matrixResult;
  
}

int main()
{
    int rowA = 0, colA = 0, rowB = 0, colB = 0; 
    float **matrixA = 0, **matrixB = 0, **matrixResult = 0;
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
    matrixA = new float*[rowA];
    for(int i = 0; i < rowA; i++){
        matrixA[i] = new float[colA];
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
    matrixB = new float*[rowB];
    for(int i = 0; i < rowB; i++){
        matrixB[i] = new float[colB];
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
            if(rowA == rowB && colA == colB){
                // if the number of rows and columns are the same 
                matrixResult = addMatrix(matrixA,matrixB,rowA,rowB,colA,colB);
                // print the resulting matrix
                for(int i = 0; i < rowA; i++){
                    for(int j = 0; j < colB; j++){
                        cout << *(*(matrixResult+i)+j) << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            
            else{
                cout << "The two matrix cannot be added" << endl;
            }
        }
        
        else if(option == 'S' or option == 's'){
            if(rowA == rowB && colA == colB){
                // if the number of rows and columns are the same 
                matrixResult = subtractMatrix(matrixA,matrixB,rowA,rowB,colA,colB);
                // print the resulting matrix
                for(int i = 0; i < rowA; i++){
                    for(int j = 0; j < colB; j++){
                        cout << *(*(matrixResult+i)+j) << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            
            else{
                cout << "The two matrix cannot be subtracted" << endl;
            }
        }
        
        else if(option == 'M' or option == 'm'){
            
            if(colA == rowB){
                // if the number of columns in the first matrix equals to the number 
                // of rows in the second matrix
                matrixResult = multiplyMatrix(matrixA,matrixB,rowA,rowB,colA,colB);
                // print the resulting matrix
                for(int i = 0; i < rowA; i++){
                    for(int j = 0; j < colB; j++){
                        cout << *(*(matrixResult+i)+j) << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            
            else{
                cout << "The two matrix cannot be multiplied" << endl;
            }
        }
        
        else if(option == 'N' or option == 'n'){
            cout << "Please enter the number of rows and columns of the first matrix: " << endl;
            cout << "row: ";
            cin >> rowA;
            cout << "column: ";
            cin >> colA;
            
            cout << "Please enter the first matrix: " << endl;
            matrixA = new float*[rowA];
            for(int i = 0; i < rowA; i++){
                matrixA[i] = new float[colA];
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
            matrixB = new float*[rowB];
            for(int i = 0; i < rowB; i++){
                matrixB[i] = new float[colB];
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














