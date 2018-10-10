// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0
#include <iostream>
#include <cassert>
#include <iomanip>


using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    matrix mat1,mat2;
    int row,col,row2,col2;
    cout<<"Enter the numbr of rows ";
    cin>>row;
    cout<<"Enter the number of columns ";
    cin>>col;
    int number=(row*col);
    int arr1[number];
    cout<<"Enter the number of rows for the other matrix :";
    cin>>row2;
    cout<<"Enter the number of columns for the other matrix";
    cin>>col2;
    int number2=(row2*col2);
    cout<<"Enter Mat1 "<<endl;
    for(int i=0; i<number; i++)
    {
        int elemnt;
        cin>>elemnt;
        arr1[i]=elemnt;
    }
    int arr2[number2];
    cout<<"Enter Mat2 "<<endl;
    for(int i=0; i<number2; i++)
    {
        int elemnt;
        cin>>elemnt;
        arr2[i]=elemnt;
    }
    createMatrix(row,col,arr1,mat1);
    createMatrix(row2,col2,arr2,mat2);
      cout << "Mat1= " << endl<<mat1 << endl;
      cout << "Mat2= " <<endl<< mat2 << endl;

      cout << "(mat1 + mat2)= " <<endl<< mat1 + mat2 << endl << endl;
      cout << "(mat2 + mat2)" <<endl << mat2 + mat2 << endl << endl;
      cout <<"++mat1= ";
      ++mat1;
      cout << mat1 << endl;
     cout <<"mat1+= mat2 += mat2= " << endl;
      mat1+= mat2 += mat2;
      cout << mat1 << endl;
      cout << mat2 << endl;
      cout << "Transpose mat1= " << endl ;
      cout<<  transpose(mat1);
      if ( mat1 == mat2 )
        {cout <<"Yes";}
    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}
//_________________________________________________
matrix operator +  (matrix mat1, matrix mat2)
{
    matrix NEW ;
    if ( mat1.col ==mat2.col && mat1.row == mat2.row)
    {
        int num [mat1.row*mat1.col];
        int col = mat1.col;
        int row = mat1.row;
        createMatrix(row,col,num,NEW);
        for (int i = 0 ; i<NEW.row ; i++)
            for (int j =0 ; j<NEW.col ; j++)
                NEW.data[i][j]= mat1.data[i][j] + mat2.data[i][j];
    }
    else
        cout <<"Error .." ;
    return NEW;
}
//_________________________________________________
matrix operator -  (matrix mat1, matrix mat2)
{
    matrix NEW ;
    if ( mat1.col ==mat2.col && mat1.row == mat2.row)
    {
        int num [mat1.row*mat1.col];
        int col = mat1.col;
        int row = mat1.row;
        createMatrix(row,col,num,NEW);
        for (int i = 0 ; i<NEW.row ; i++)
            for (int j =0 ; j<NEW.col ; j++)
                NEW.data[i][j]= mat1.data[i][j] - mat2.data[i][j];
    }
    else
        cout <<"Error .." ;
}
//_______________________________________________
matrix operator *  (matrix mat1, matrix mat2)
{
    matrix NEW ;
    if ( mat1.col ==mat2.row )
    {
        int num [mat1.row*mat1.col];
        int col = mat1.col;
        int row = mat1.row;
        createMatrix(row,col,num,NEW);
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat2.col; j++)
            {
                NEW.data[i][j] = 0;
                for (int k = 0; k < mat2.col; k++)
                {
                    NEW.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
                }
            }
        }
    }
    else
        cout <<"Error .." ;
}
//____________________________________________________
matrix operator +  (matrix mat1, int scalar)
{
    matrix NEW ;
    int num [mat1.row*mat1.col];
    int col = mat1.col;
    int row = mat1.row;
    createMatrix(row,col,num,NEW);
    for (int i = 0 ; i<NEW.row ; i++)
        for (int j =0 ; j<NEW.col ; j++)
            NEW.data[i][j]= mat1.data[i][j] +scalar ;
}

//____________________________________________________
matrix operator -  (matrix mat1, int scalar)
{
    matrix NEW ;
    int num [mat1.row*mat1.col];
    int col = mat1.col;
    int row = mat1.row;
    createMatrix(row,col,num,NEW);
    for (int i = 0 ; i<NEW.row ; i++)
        for (int j =0 ; j<NEW.col ; j++)
            NEW.data[i][j]= mat1.data[i][j] -scalar ;
}

//____________________________________________________
matrix operator *  (matrix mat1, int scalar)
{
    matrix NEW ;
    int num [mat1.row*mat1.col];
    int col = mat1.col;
    int row = mat1.row;
    createMatrix(row,col,num,NEW);
    for (int i = 0 ; i<NEW.row ; i++)
        for (int j =0 ; j<NEW.col ; j++)
            NEW.data[i][j]= mat1.data[i][j] *scalar ;
}
//___________________________________________________
matrix operator+= (matrix & mat1, matrix mat2)
{

    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+mat2.data[i][j];

        }
    }
    return mat1;
}
//___________________________________________________

matrix operator -=(matrix& mat1, matrix mat2)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
        }
    }
    return mat1;
}
//___________________________________________________
void operator++ (matrix& mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            mat.data[i][j]=mat.data[i][j]+1;
        }
    }
}
//____________________________________________________
void operator-- (matrix& mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            mat.data[i][j]=mat.data[i][j]-1;
        }
    }
}
//___________________________________________________
matrix operator+= (matrix& mat, int scalar){

for (int i=0; i<mat.row; i++)
    {
        for (int j=0; j<mat.col; j++){
         mat.data[i][j]=mat.data[i][j]+scalar ;
        }

} return mat ;
}
//___________________________________________________
matrix operator-= (matrix& mat, int scalar){

for (int i=0; i<mat.row; i++)
    {
        for (int j=0; j<mat.col; j++){
         mat.data[i][j]=mat.data[i][j]-scalar ;}}


return mat ; }
//___________________________________________________
bool operator == (matrix mat1, matrix mat2)
{
    bool identical=true ;
    if ((mat1.row==mat2.row) && (mat1.col ==mat2.col))
    {
        for (int i = 0 ; i<mat1.row ; i++)
        {
            for (int j =0 ; j<mat1.col ; j++)
            {
                if (mat1.data[i][j]!=mat2.data[i][j])
                    identical= false;
            }
        }
    }
    else
        identical= false;
    return identical ;
}
//______________________________________________
bool   operator != (matrix mat1, matrix mat2)
{
    bool notsame=false ;
    if ((mat1.row==mat2.row) && (mat1.col ==mat2.col))
    {
        for (int i = 0 ; i<mat1.row ; i++)
        {
            for (int j =0 ; j<mat1.col ; j++)
            {
                if (mat1.data[i][j]!=mat2.data[i][j])
                    notsame= true;
            }
        }
    }
    else
        notsame= true;
    return notsame ;
}
//________________________________________________
bool   isSquare   (matrix mat)
{
    bool isSquare ;
    if (mat.row==mat.col)
        isSquare= true ;
    else
        isSquare=false;
    return isSquare;
}
//__________________________________________________
bool   isSymetric (matrix mat)
{
    bool isSymetric=true ;
    if (mat.col== mat.row)
    {
        for(int i=0; i<mat.row; i++)
            for(int j=0; j<mat.col; j++)
                if(mat.data[i][j]!=mat.data[j][i])
                    isSymetric= false;
    }
    else
        isSymetric=false;
    return isSymetric;
}
//__________________________________________________

bool   isIdentity (matrix mat)
{
    bool isIdentity=true;

    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            if (i==j && mat.data[i][j]!= 1)
                isIdentity=false;
            else if (i!=j && mat.data[i][j]!=0)
                isIdentity=false;
        }
    }
    return isIdentity;
}
//__________________________________________________
ostream& operator <<(ostream& out,matrix mat)
{
    for (int i=0; i<mat.row; i++)
    {
        for (int j=0; j<mat.col; j++)
    {
            out<<mat.data[i][j]<< "   ";
        }
        out<<endl;
    }
    return out ;
}
//___________________________________________________
matrix transpose(matrix mat)
{
    matrix NEW ;
        int num [mat.row*mat.col];
        int col = mat.col;
        int row = mat.row;
        createMatrix(row,col,num,NEW);
        for (int i = 0 ; i<NEW.row ; i++)
            for (int j =0 ; j<NEW.col ; j++)
                NEW.data[i][j]= mat.data[j][i];

    return NEW;
}
//__________________________________________________



