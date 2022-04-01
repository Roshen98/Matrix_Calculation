// Liangjie Shen
#include <iostream>
#include <time.h>       
using namespace std;

class Matrix
{
    private:
        // private variables: not accessed outside class
        int row , col;
        float **matrix, **matrixResult;

	public:
	    Matrix(); // constructor
		~Matrix(); // destructor

        // operator overloads
		void operator+(Matrix m);
		void operator-(Matrix m);
		void operator*(Matrix m);
		
		// getter and setter methods
        int getRow();
        int getCol();
        void setRow(int row);
        void setCol(int col);
		void getInput();

};

// constructor
Matrix::Matrix(){
    row = 0;
    col = 0;
    matrix = 0;
    matrixResult = 0;
}


//destructor
Matrix::~Matrix(){ 
    ;
//	delete[] matrix;
    
}
    
int Matrix::getRow(){
    // get row
    return row;
}

int Matrix::getCol(){
    // get column
    return col;
}

void Matrix::setRow(int row){
    // set row
    this->row = row;
}

void Matrix::setCol(int col){
    // set column
    this->col = col;
}

void Matrix::operator+(Matrix m){
    // overload operator to add the two matrices
    
	matrixResult = new float * [row];
    
    for(int i = 0; i < row; i++){
        matrixResult[i] = new float[col];
        for(int j = 0; j < col; j++){
            *(*(matrixResult+i)+j) = *(*(matrix+i)+j) + *(*(m.matrix+i)+j);
            
        }
    }
	
	// prints matrix
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			cout  <<  *(*(matrixResult+i)+j) << " ";
		}
		cout << endl;
	}
	
  
}

void Matrix::operator-(Matrix m){
    // overload operator to subtract the two matrices
    
	matrixResult = new float * [row];
    
    for(int i = 0; i < row; i++){
        matrixResult[i] = new float[col];
        for(int j = 0; j < col; j++){
            *(*(matrixResult+i)+j) = *(*(matrix+i)+j) - *(*(m.matrix+i)+j);
            
        }
    }
	
	// prints matrix
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			cout  <<  *(*(matrixResult+i)+j) << " ";
		}
		cout << endl;
	}
}

void Matrix::operator*(Matrix m){
    // overload operator to multiply the two matrices
    
	matrixResult = new float * [row];
    clock_t start = clock (); // time starts
    for(int i = 0; i < row; i++){
        matrixResult[i] = new float[col];
        for(int j = 0; j < col; j++){
            *(*(matrixResult+i)+j) = 0;
            for(int k = 0; k < col; k++){
                *(*(matrixResult+i)+j) += *(*(matrix+i)+k) * *(*(m.matrix+k)+j);
            }
            
        }
    }
    // time ends and time taken are calculated
    cout << "Time Taken for Multiplication: " << 
            (((float)( clock() - start )) / CLOCKS_PER_SEC)*1000000000 << " nano seconds." << endl;
	
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			cout  <<  *(*(matrixResult+i)+j) << " ";
		}
		cout << endl;
	}
	
}

void Matrix::getInput(){
    // get the input of rows, columns and matrices
    while(row < 1 || col < 1){
    
        cout << "row: ";
        cin >> row;
        cout << "column: ";
        cin >> col;
        
        if(row < 1 || col < 1)
            cout << "Invalid input!" << endl;
    }
    
    cout << "Please enter the matrix: " << endl;
    matrix = new float*[row];
    for(int i = 0; i < row; i++){
        matrix[i] = new float[col];
        for(int j = 0; j < col; j++){
            cin >> matrix[i][j];
        }
    }
}

int main()
{
    Matrix m1,m2;
    char option;
    
    cout << "Welcome to the matrix world!" << endl;
    
    cout << "Please enter the number of rows and columns of the first matrix: " << endl;
    
    m1.getInput();

    cout << "Please enter the number of rows and columns of the second matrix: " << endl;
    
    m2.getInput();
    
    while(true){
        
        cout << "\nWhat do you wish to do?(Enter A, S, M, N or E)" << endl;
        cout << "A : Addition" << endl;
        cout << "S : Subtraction" << endl;
        cout << "M : Multiplication" << endl;
        cout << "N : New Matrix" << endl;
        cout << "E : Exit" << endl;
        cin >> option;
        cout << endl;
        
        if(option == 'A' or option == 'a'){
            if(m1.getRow() == m2.getRow() && m1.getCol() == m2.getCol()){
                // if the number of rows and columns are the same 
                m1+m2;
            }
            
            else{
                cout << "The two matrix cannot be added" << endl;
            }
        }
        
        else if(option == 'S' or option == 's'){
            if(m1.getRow() == m2.getRow() && m1.getCol() == m2.getCol()){
                // if the number of rows and columns are the same 
                m1-m2;
            }
            
            else{
                cout << "The two matrix cannot be subtracted" << endl;
            }
        }
        
        else if(option == 'M' or option == 'm'){
            
            if(m1.getCol() == m2.getRow()){
                // if the number of columns in the first matrix equals to the number 
                // of rows in the second matrix
                m1*m2;
            }
            
            else{
                cout << "The two matrix cannot be multiplied" << endl;
            }
        }
        
        else if(option == 'N' or option == 'n'){
            cout << "Please enter the number of rows and columns of the first matrix: " << endl;
    
            m1.getInput();
        
            cout << "Please enter the number of rows and columns of the second matrix: " << endl;
            
            m2.getInput();
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














