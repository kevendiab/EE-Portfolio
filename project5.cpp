//////////////////////////////////////////////////// PROJECT 5 ///////////////////////////////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "/mnt/ee259dir/tools/pro_5/inversion.h"

using namespace std;

ofstream o_f("output.txt", ios::out);

class MATRIX: public PROGRAM_BANK{

	// there are two friend functions:
	friend MATRIX operator / (int, MATRIX); 
			// FRIEND FUNCTION; example: 5 / X;
			// Compute inverse of X using INHERITANCE;
			// Multiply each element of inverted matrix by 5; 
			// store the results into a temp MATRIX;
			// return the temp MATRIX;
	
	friend MATRIX operator * (int, MATRIX); 
			// FRIEND FUNCTION; example: 5 * X;
			// each element of the matrix X is 
			// multiplied by 5;
			// store the results into a temp MATRIX;
			// return the temp MATRIX;

	public:	// public interfaces for this class
	
	  MATRIX (int, int); // constructor;
			// example: MATRIX X(d1,d2);
			// creates a matrix object with
			// private variables dim1 = d1 and dim2 = d2
			// and initializes each element to 0;
  
	  MATRIX(int, int, char *); // constructor;
			// example: MATRIX X(d1,d2,"in_name");
			// read the elements of the matrix
			// from a given file in_name; d1 and d2 are 
			// the two dimensions of the matrix;
				
	  void PRINT(char *);	// example: X.PRINT("W");
			// print the elements of the matrix X
			// into output.txt file;
			// returns no values;

	  bool  operator < (int); //example: if( X < b )
			// check if the minimum element of the matrix X
			// is less than b
			// if so, it returns true; otherwise, it returns false;
	
	  void operator = (MATRIX); // example: X = Y;
			// Copy Y to X;
			// returns no values;		
		
	  void operator += (MATRIX);  // example: X += Y;
                        // matrix addition;
                        // store the results in X;
			// values of Y remain unchanged;
			// returns no values;
		
	  void operator *= (MATRIX); // example: X *= Y;
			// matrix multiplication;
			// store the results in X;
			// values of Y remain unchanged;
			// returns no values;

	  MATRIX operator + (MATRIX); // example: X + Y;
			// Create a temp matrix object; 
			// add each element of Y to each element of X
			// and assign to temp;
			// return this temp matrix object;
			// values of X and Y remain unchanged;

	  MATRIX operator * (MATRIX); // example: X * Y;
			// matrix multiplication;
			// store the results into a temp matrix
			// and return this temp matrix;
			// values of Y remain unchanged;

	  MATRIX operator / (MATRIX); // example: X / Y;
			// get inverse of Y and multiply it with X;
			// put the results into a temp MATRIX
			// and return temp MATRIX;
			// X and Y remain unchanged;
			// USE INHERITENCE FOR MATRIX INVERSION;
	
	protected:
  	  int dim1, dim2; // dimensions of the matrix;
		// if dim2 is 1, a vector (no need for special
		// handling of vectors; everything should work
		// for both matrices and vectors)
  	  double A[20][20]; // 2-D array for matrix elements;
	  char in_file[11]; // input file name for this object;
 };


// FIRST CONSTRUCTOR
MATRIX::MATRIX(int d1, int d2)
        :PROGRAM_BANK(d1) // CALL THE CONSTRUCTOR OF THE BASE CLASS
{
	 // your constructor code goes below:
     int i, j;
     dim1 = d1;
     dim2 = d2;
     
     if(d1 < 0 || d1 > 20 || d2< 0 || d2 >20)
     {
	  return;
     }
     else
     {
     	for (i= 0; i < dim1; i++)
     	{
         	for (j= 0; j < dim2; j++)
         	{
             		A[i][j] = 0;
         	}
     	}
     }
}

// SECOND CONSTRUCTOR
MATRIX::MATRIX(int d1, int d2, char * file_name)
        :PROGRAM_BANK(d1, file_name) // CALL THE CONSTRUCTOR OF THE BASE CLASS
{
	int i, j;
	o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
           
	if(d1 < 0 || d1 > 20 || d2< 0 || d2 >20)
	{
		o_f <<"+++ P5_OUTPUT >>> INPUT ERROR" 
           	       << endl
           	       <<"+++ P5_OUTPUT >>> UNABLE TO CREATE MATRIX" 
           	       << endl
           	       <<"+++ P5_OUTPUT >>> EXITING PROGRAM" 
           	       << endl
          	       << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" 
          	       << endl;
           //exit (1);
		return;
	}    
	else
	{
		dim1 = d1;
		dim2 = d2;
		// copy the input file name to private variable in_file
		strcpy(in_file, file_name);

		//define the input_filein this current block
		ifstream input_file(in_file, ios::in);

		for (i =0; i < dim1; i++)
		{
			for(j = 0; j < dim2; j++)
			{
				input_file >> A[i][j];
			}
		}
		input_file.close(); // close input file;
		input_file.clear(); // rewind file pointer to the top of the file;
		o_f <<"+++ P5_OUTPUT >>> CREATED A " << dim1 <<" X " << dim2 
			<<" MATRIX FROM " << in_file << endl;
	} 
	o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

// friend function
MATRIX operator / (int c, MATRIX a_matrix)
{ 
    int i ,j;
    MATRIX temp_matrix(a_matrix.dim1, a_matrix.dim2);
     
    a_matrix.INVERT_MATRIX("OUT_5_TEMP.txt");
    ifstream input_file_temp("OUT_5_TEMP.txt", ios::in);
     
    for(i = 0; i < a_matrix.dim1; i++)
    {
        for(j = 0; j < a_matrix.dim2; j++)
        {
      	input_file_temp >> temp_matrix.A[i][j];
        temp_matrix.A[i][j] *= c;
        }
    }
     
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    o_f << "+++ P5_OUTPUT >>> THE RESULT OF " << c << "/" << " X OPERATION IS:" << endl;
    for(i = 0; i < temp_matrix.dim1; i++)
    {
        for(j = 0; j < temp_matrix.dim2; j++)
        {
            o_f << setprecision(2) << fixed << temp_matrix.A[i][j] << " ";
        }
        o_f << endl;
    }
    o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
     
    return temp_matrix;
}

// friend function
MATRIX operator * (int c, MATRIX a_matrix)
{ 
    int i,j;
    MATRIX temp_matrix(a_matrix.dim1, a_matrix.dim2);
     
    for(i = 0; i < a_matrix.dim1; i++)
    {
        for(j = 0; j < a_matrix.dim2; j++)
        {
            temp_matrix.A[i][j] = a_matrix.A[i][j] * c;
        }
    }
     
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    o_f << "+++ P5_OUTPUT >>> THE RESULT OF " << c << "* X OPERATION IS:" << endl;
    for(i = 0; i < temp_matrix.dim1; i++)
    {
        for(j = 0; j < temp_matrix.dim2; j++)
        {
           o_f << setprecision(2) << fixed << temp_matrix.A[i][j] << " ";
        }
        o_f << endl;
    }
    o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
     
    return temp_matrix;
}

void
MATRIX::PRINT(char * NAME)
{
    int i,j;
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    o_f << "+++ P5_OUTPUT >>> CONTENTS OF MATRIX " << NAME << " IS:" << endl;
    for(i = 0; i < dim1; i++)
    {
        for(j = 0; j < dim2; j++)
        {
            o_f << setprecision(2) << fixed << A[i][j] << " ";
        }
        o_f << endl;
    }
    o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

bool
MATRIX::operator < (int b)
{

int i,j;
double min;
min = A[0][0];
for(i = 0; i < dim1; i++)
    {
    	for(j = 0; j < dim2; j++)
        {
            if(A[i][j] < min)
            {
            min = A[i][j];
            }
        }
    }
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    if(min < b)
    {
        o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR < RETURNING TRUE" << endl;
        o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
        return true;
    }
    else
    {
        o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR < RETURNING FALSE" << endl;
        o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
        return false;
    }
}

void
MATRIX::operator = (MATRIX  a_matrix)
{
    int i,j;
    for(i = 0; i < dim1; i++)
    {
        for(j = 0; j < dim2; j++)
        {
            A[i][j] = a_matrix.A[i][j];
        }
    }
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED" << endl;
    o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void
MATRIX::operator += (MATRIX a_matrix)
{
    int i,j;
    for(i = 0; i < dim1; i++)
    {
        for(j = 0; j < dim2; j++)
        {
            A[i][j] += a_matrix.A[i][j];
        }
    }
}

void
MATRIX::operator *= (MATRIX a_matrix)
{
    MATRIX temp_matrix(dim1, a_matrix.dim2);
    int i, j, k;
    
    for(i = 0; i < dim1; i++)
    {
        for(j = 0; j < a_matrix.dim2; j++)
        {
            temp_matrix.A[i][j] = 0;
            for(k = 0; k < dim2; k++)
            {
                temp_matrix.A[i][j] += A[i][k] * a_matrix.A[k][j];
            }
        }
    }
    
    for(i = 0; i < dim1; i++)
    {
        for(j = 0; j < a_matrix.dim2; j++)
        {
            A[i][j] = temp_matrix.A[i][j];
        }
    }
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR *= COMPLETED" << endl;
    o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

MATRIX
MATRIX::operator + (MATRIX a_matrix)
{
    MATRIX temp_matrix(dim1, dim2);
    for(int i = 0; i < dim1; i++)
    {
        for(int j = 0; j < dim2; j++)
        {
            temp_matrix.A[i][j] = A[i][j] + a_matrix.A[i][j];
        }
    }
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR + COMPLETED" << endl;
    o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
    return temp_matrix;
}

MATRIX
MATRIX::operator * (MATRIX a_matrix)
{
    MATRIX temp_matrix(dim1, a_matrix.dim2);
    int i, j, k;
    for(i = 0; i < dim1; i++)
    {
        for(j = 0; j < a_matrix.dim2; j++)
        {
            temp_matrix.A[i][j] = 0;
            for(k = 0; k < dim2; k++)
            {
                temp_matrix.A[i][j] += A[i][k] * a_matrix.A[k][j];
            }
        }
    }
    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR * COMPLETED" << endl;
    o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
    return temp_matrix;
}

MATRIX
MATRIX::operator / (MATRIX a_matrix)
{
    int i, j, k;

    a_matrix.INVERT_MATRIX("OUT_5_TEMP.txt");
    MATRIX inv_matrix(a_matrix.dim2, a_matrix.dim1,"OUT_5_TEMP.txt");
    MATRIX temp_matrix(dim1, a_matrix.dim2);

    for(i = 0; i < dim1; i++)
    {
        for(j = 0; j < a_matrix.dim2; j++)
        {
            temp_matrix.A[i][j] = 0;
            for(k = 0; k < dim2; k++)
            {
                temp_matrix.A[i][j] += A[i][k] * inv_matrix.A[k][j];
            }
        }
    }

    o_f << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    o_f << "+++ P5_OUTPUT >>> OVERLOADED OPERATOR / COMPLETED" << endl;
    o_f << "+++ P5_OUTPUT >>> THE RESULT OF X/Y OPERATION IS:" << endl;
    for(i = 0; i < temp_matrix.dim1; i++)
    {
        for(j = 0; j < temp_matrix.dim2; j++)
        {
            o_f << setprecision(2) << fixed << temp_matrix.A[i][j] << " ";
        }
        o_f << endl;
    }
    o_f << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;

    return temp_matrix;
}