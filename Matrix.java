// Liangjie Shen
import java.util.Scanner;  // importing class for user input
public class Matrix
{
    private final int SIZE = 100; // limit size of matrix to 100
    private int row;
    private int col;
    private float[][] matrix;
    private char option;
    // private variables: not accessed outside the class
    
    public Matrix(int row, int col){
        // constructor
        this.row = row;
        this.col = col;
        matrix = new float[row][col];
    }
    
    public void fill(float[][] matrix) {
        // fills the class with the matrix
        this.matrix = new float[row][col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                this.matrix[i][j] = matrix[i][j];
    }
    
    
    public void addMatrix(Matrix matrixB){
        // function to add the two matrices
        Matrix matrixA = this;
        Matrix matrixResult = new Matrix(SIZE,SIZE);
      
        if(matrixA.row == matrixB.row && matrixA.col == matrixB.col){
            
            // if the number of rows and columns are the same 
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
            
                    matrixResult.matrix[i][j] = matrixA.matrix[i][j] + matrixB.matrix[i][j];
                }
            }
            // print the resulting matrix
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    System.out.print(matrixResult.matrix[i][j] + " ");
                }
                System.out.println();
            }
        }
        
        else{
            System.out.println("The two matrix cannot be added");
        }
    }
    
    public void subtractMatrix(Matrix matrixB){
        // function to subtract the two matrices
        Matrix matrixA = this;
        Matrix matrixResult = new Matrix(SIZE,SIZE);
      
        if(matrixA.row == matrixB.row && matrixA.col == matrixB.col){
            
            // if the number of rows and columns are the same 
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
            
                    matrixResult.matrix[i][j] = matrixA.matrix[i][j] - matrixB.matrix[i][j];
                }
            }
            // print the resulting matrix
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    System.out.print(matrixResult.matrix[i][j] + " ");
                }
                System.out.println();
            }
        }
        
        else{
            System.out.println("The two matrix cannot be subtracted");
        }
    }
    
    public void multiplyMatrix(Matrix matrixB){
        // function to multiply the two matrices
        Matrix matrixA = this;
        Matrix matrixResult = new Matrix(SIZE,SIZE);
      
        if(matrixA.col == matrixB.row){
            
            // if the number of rows and columns are the same 
            long start = System.nanoTime();
            // start time
            for(int i = 0; i < matrixA.row; i++){
                for(int j = 0; j < matrixB.col; j++){
                    matrixResult.matrix[i][j] = 0;
                    for(int k = 0; k < matrixA.col; k++){
                        matrixResult.matrix[i][j] += matrixA.matrix[i][k] * matrixB.matrix[k][j];
                    }
                }
            }
            // time ends and calculate the time taken
            long end = System.nanoTime();
            float time = (end - start); 
            System.out.print("Time Taken for Multiplication: ");
            System.out.println(time + " nano seconds");
            System.out.println();
            
            // print the resulting matrix
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    System.out.print(matrixResult.matrix[i][j] + " ");
                }
                System.out.println();
            }
        }
        
        else{
            System.out.println("The two matrix cannot be multiplied");
        }
    }

	public static void main(String[] args) {
	    
	    final int SIZE = 100; // limit size of matrix to 100
        int rowA = 0, colA = 0, rowB = 0, colB = 0; 
        float[][] matrixA = new float[SIZE][SIZE];
        float[][] matrixB = new float[SIZE][SIZE];
        char option;
        Scanner scanner = new Scanner(System.in);  // declare Scanner
        
		System.out.println("Welcome to the matrix world!");
		
		System.out.println("Please enter the number of rows and columns of the first matrix: ");
		System.out.print("row: ");
		rowA = scanner.nextInt();  // input
		System.out.print("column: ");
		colA = scanner.nextInt();  
		System.out.println("Please enter the matrix: ");
		for(int i = 0; i < rowA; i++){
            for(int j = 0; j < colA; j++){
                 matrixA[i][j] = scanner.nextFloat();
            }
        }
		
        System.out.println("Please enter the number of rows and columns of the second matrix: ");
		System.out.print("row: ");
		rowB = scanner.nextInt();  // input
		System.out.print("column: ");
		colB = scanner.nextInt();  
		System.out.println("Please enter the matrix: ");
		for(int i = 0; i < rowB; i++){
            for(int j = 0; j < colB; j++){
                 matrixB[i][j] = scanner.nextFloat();
            }
        }
        Matrix m1 = new Matrix(rowA,colA);
        m1.fill(matrixA);
        Matrix m2 = new Matrix(rowB,colB);
        m2.fill(matrixB);
       
        System.out.println();
		
		while(true){
		    System.out.println("\nWhat do you wish to do?(Enter A, S, M, N or E)");
		    System.out.println("Addition");
		    System.out.println("Subtraction");
		    System.out.println("Multiplication");
		    System.out.println("New Matrix");
		    System.out.println("Exit");
		    option = scanner.next().charAt(0);
		    System.out.println();
		    
		    if(option == 'A' || option == 'a'){
                m1.addMatrix(m2);
                System.out.println();
            }
            
            else if(option == 'S' || option == 's'){
                m1.subtractMatrix(m2);
                System.out.println();
            }
            
            else if(option == 'M' || option == 'm'){
                
                m1.multiplyMatrix(m2);
                System.out.println();
            }
            
            else if(option == 'N' || option == 'n'){
                System.out.println("Please enter the number of rows and columns of the first matrix: ");
        		System.out.print("row: ");
        		rowA = scanner.nextInt();  // input
        		System.out.print("column: ");
        		colA = scanner.nextInt();  
        		System.out.println("Please enter the first matrix: ");
        		for(int i = 0; i < rowA; i++){
                    for(int j = 0; j < colA; j++){
                         matrixA[i][j] = scanner.nextFloat();
                    }
                }
                
                System.out.println("Please enter the number of rows and columns of the second matrix: ");
        		System.out.print("row: ");
        		rowB = scanner.nextInt();  // input
        		System.out.print("column: ");
        		colB = scanner.nextInt();  
        		System.out.println("Please enter the second matrix: ");
        		for(int i = 0; i < rowB; i++){
                    for(int j = 0; j < colB; j++){
                         matrixB[i][j] = scanner.nextFloat();
                    }
                }
                m1 = new Matrix(rowA,colA);
                m1.fill(matrixA);
                m2 = new Matrix(rowB,colB);
                m2.fill(matrixB);
                System.out.println();
            }
            
            else if(option == 'E' || option == 'e'){
                break;
            }
            
            else{
                
                System.out.println("wrong option please try again!");
                System.out.println();
            }
		}
	}
    
}


