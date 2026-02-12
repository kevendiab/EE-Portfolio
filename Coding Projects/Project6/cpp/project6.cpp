#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include "/mnt/ee259dir/tools/pro_5/sample_p5.h"
//#include "sample_p5.h"

using namespace std;

//ofstream output("out.6.txt", ios::app);

class LINEAR_SOLVER: public MATRIX{
   public:
    LINEAR_SOLVER(int);  // constructor 1; 
            // example: s.LINEAR_SOLVER(5);
            // there are 5 equations and 5 variables;
    
    LINEAR_SOLVER(char *, int);  // constructor 2; 
            // example: s.LINEAR_SOLVER("i_f.txt",5);
            // there are 5 eqs and 5 vars in i_f.txt;

    void SOLVE_LINEAR_EQUATION(char *); // example: s.SOLVE_LINEAR_EQUATION("ASCEND");
            // solve the linear equations and
            // sort the output in ascending order;
            // if the input is "DESCEND" then the order
            // of the output is descending;
            // returns no values;

    void SOLVE_BY_MATLAB(void); // example: s.SOLVE_BY_MATLAB();
            // generate and run a MATLAB program to 
            // solve a set of linear equations;
            // returns no values;

    void SOLVE_BY_PYTHON(void); // example: s.SOLVE_BY_PYTHON();
            // generate and run a Python script to 
            // solve a set of linear equations;
            // returns no values;

    void INHERITED_INVERT(void); // example: s.INHERITED_INVERT();
            // perform matrix inversion on
            // the input system by inheriting
            // from PROGRAM_BANK class;
            // returns no values;

    void INVERT_BY_MATLAB(void); // example: s.INVERT_BY_MATLAB();
            // generate and run a MATLAB program to 
            // invert a matrix;
            // returns no values;

    void INVERT_BY_PYTHON(void); // example: s.INVERT_BY_PYTHON();
            // generate and run a Python acript to 
            // invert a matrix;
            // returns no values;

   protected:
    int n;         // max of n is 50
    float A[50][50];
    float B[50];
};

LINEAR_SOLVER::LINEAR_SOLVER(char * p, int x)
        :MATRIX(x, x, p)
{    
    int i, j;
    n = x;
    ifstream i_f (p, ios::in);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            i_f >> A[i][j];
        }
    }
    for(i = 0; i < n; i++)
    {
        i_f >> B[i];
    }
    
    o_f << "++++++ P6 BEGIN ++++++" << endl
        << "++++++ P6 INSTANTIATED AN OBJECT WITH " << n << " EQUATIONS" << endl
        << "++++++ P6 DATA READ FROM FILE: " << p << endl
        << "++++++ P6 END ++++++" << endl;
}

LINEAR_SOLVER::LINEAR_SOLVER(int x)
        :MATRIX(x, x)
{
    n = x;
    o_f << "++++++ P6 BEGIN ++++++" << endl
        << "++++++ P6 INSTANTIATED AN OBJECT WITH " << n << " EQUATIONS" << endl
        << "++++++ P6 END ++++++" << endl;
}

void
LINEAR_SOLVER::SOLVE_LINEAR_EQUATION(char * command)

{
    int i, j, k, row, col;
    float temp_A[50][50], temp_B[50], X[50], factor, temp;
    int indices[50];

    for (i = 0; i < n; i++) 
    {
        temp_B[i] = B[i];
        indices[i] = i;
        for (j = 0; j < n; j++) 
        {
            temp_A[i][j] = A[i][j];
        }
    }

    for (col = 0; col < n; col++) 
    {
        if (temp_A[col][col] == 0) 
        {
            for (row = col + 1; row < n; row++) 
            {
                if (temp_A[row][col] != 0) 
                {
                    for (j = 0; j < n; j++) 
                    {
                        temp = temp_A[col][j];
                        temp_A[col][j] = temp_A[row][j];
                        temp_A[row][j] = temp;
                    }
                    temp = temp_B[col];
                    temp_B[col] = temp_B[row];
                    temp_B[row] = temp;
                }
            }
        }

        for (row = col + 1; row < n; row++) 
        {
            factor = temp_A[row][col] / temp_A[col][col];
            for (i = col; i < n; i++) {
                temp_A[row][i] -= factor * temp_A[col][i];
            }
            temp_B[row] -= factor * temp_B[col];
        }
    }

    for (row = n - 1; row >= 0; row--) 
    {
        X[row] = temp_B[row];
        for (col = row + 1; col < n; col++) 
        {
            X[row] -= temp_A[row][col] * X[col];
        }
        X[row] /= temp_A[row][row];
    }

    if (strcmp(command, "ASCEND") == 0) 
    {
        for (i = 0; i < n - 1; i++) 
        {
            for (j = i + 1; j < n; j++) 
            {
                if (X[i] > X[j]) 
                {
                    temp = X[i];
                    X[i] = X[j];
                    X[j] = temp;

                    int tempIndex = indices[i];
                    indices[i] = indices[j];
                    indices[j] = tempIndex;
                }
            }
        }
        o_f << "++++++ P6 BEGIN ++++++" << endl
            << "++++++ P6 MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN ASCENDING ORDER):" << endl;
    }
    else if (strcmp(command, "DESCEND") == 0) 
    {
        for (i = 0; i < n - 1; i++) 
        {
            for (j = i + 1; j < n; j++) 
            {
                if (X[i] < X[j]) 
                {
                    temp = X[i];
                    X[i] = X[j];
                    X[j] = temp;

                    int tempIndex = indices[i];
                    indices[i] = indices[j];
                    indices[j] = tempIndex;
                }
            }
        }
        o_f << "++++++ P6 BEGIN ++++++" << endl
            << "++++++ P6 MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN DESCENDING ORDER):" << endl;
    }
    else {
        o_f << "++++++ P6 BEGIN ++++++" << endl
            << "++++++ P6 MY GAUSSIAN ELIMINATION SOLUTION (UNSORTED):" << endl;
    }

    for (i = 0; i < n; i++) 
    {
        o_f << "X[" << indices[i] << "] = " << fixed << setprecision(2) << X[i] << endl;
    }
    o_f << "++++++ P6 END ++++++" << endl;
}


void
LINEAR_SOLVER::SOLVE_BY_MATLAB()
{
    int i,j;    

    ofstream matlab_file("out_62.m", ios::out); 
    matlab_file << "A=[";
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            matlab_file << A[i][j];
            if (j < n - 1) matlab_file << ",";
        }
        if (i < n - 1) matlab_file << ";";
    }
    matlab_file << "];" << endl;

    matlab_file << "B=[";
    for (i = 0; i < n; i++) 
    {
        matlab_file << B[i];
        if (i < n - 1) matlab_file << ";";
    }
    matlab_file << "];" << endl;

    matlab_file << "X=inv(A)*B;" << endl
                << "fid=fopen('output.txt','a');" << endl
                << "fprintf(fid,'++++++ P6 BEGIN ++++++\\n');" << endl
                << "fprintf(fid,'++++++ P6 RESULT FROM MATLAB (UNSORTED):\\n');" << endl
                << "for k=1:" << n << endl
                << "fprintf(fid,'X[%d]=%6.2f\\n',k-1,X(k));" << endl
                << "end" << endl
                << "fprintf(fid,'++++++ P6 END ++++++\\n');" << endl;

    system("matlab < out_62.m");
}

void 
LINEAR_SOLVER::INHERITED_INVERT()
{
    o_f << "++++++ P6 BEGIN ++++++" << endl
        << "++++++ P6 AFTER INHERITING FROM MATRIX CLASS, MY RESULT IS:" << endl;
    
    MATRIX temp_m(n, n, in_file);
    1/temp_m;
    
    o_f << "++++++ P6 END ++++++" << endl;
}

void
LINEAR_SOLVER::INVERT_BY_MATLAB()
{
    int i,j; 

    ofstream matlab_file("out_63.m");
    matlab_file << "A=[";
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            matlab_file << A[i][j];
            if (j < n - 1) matlab_file << ",";
        }
        if (i < n - 1) matlab_file << ";";
    }
    matlab_file << "];" << endl;

    matlab_file << "X=inv(A);" << endl
                << "fid=fopen('output.txt','a');" << endl
                << "fprintf(fid,'++++++ P6 BEGIN ++++++\\n');" << endl
                << "fprintf(fid,'++++++ P6 INVERSION RESULT FROM MATLAB: \\n');" << endl
                << "for i=1:" << n << endl
                << "for j=1:" << n << endl
                << "fprintf(fid,'X[%d][%d]=%6.2f ',i-1,j-1,X(i,j));" << endl
                << "end" << endl
                << "fprintf(fid,'\\n');" << endl
                << "end" << endl
                << "fprintf(fid,'++++++ P6 END ++++++\\n');" << endl;

    system("matlab < out_63.m");
}

void
LINEAR_SOLVER::SOLVE_BY_PYTHON(void)
{
    int i, j;
    ofstream output_file_py ("out_64.py");
    output_file_py << "import numpy as np" << endl;
    output_file_py << "from numpy.linalg import inv" << endl << endl;
    output_file_py << "A = np.matrix('";
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
        output_file_py << A[i][j];
        if (j < n - 1)         
            output_file_py << ' ';
        }
        if (i < n - 1)            
            output_file_py << "; ";
    }
    output_file_py << "')" << endl;
    output_file_py << "B = np.matrix('" ;
    for(i = 0; i < n; i++)
    {
        output_file_py << B[i];
        if (i < n-1)
        {
            output_file_py << "; ";
        }
    }
    output_file_py << "')" << endl;
    output_file_py << "X = np.matmul(inv(A), B)" << endl;
    output_file_py << "" << endl; 
    output_file_py << "out_file = open(\"output.txt\", \"a\")" << endl;
    output_file_py << "out_file.write('++++++ P6 BEGIN ++++++\\n')" << endl;
    output_file_py << "out_file.write('++++++ P6 RESULT FROM PYTHON (UNSORTED):\\n')" << endl;
    output_file_py << "" << endl; 
    output_file_py << "for k in range(" << n << "):" << endl;
    output_file_py << "\tout_file.write(f'X[{k}]={X.item(k):.2f}\\n')" << endl;
    output_file_py << "" << endl; 
    output_file_py << "out_file.write('++++++ P6 END ++++++\\n')" << endl;
    output_file_py << "out_file.close()" << endl;
    system("python3 out_64.py");
}



void LINEAR_SOLVER::INVERT_BY_PYTHON(void)
{
    
    int i,j;
    ofstream output_file_py("out_65.py", ios::out);
    output_file_py << "import numpy as np\n";
    output_file_py << "from numpy.linalg import inv\n\n";

    output_file_py << "A = np.matrix('";
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            output_file_py << A[i][j];
            if (j < n - 1) output_file_py << " ";
        }
        if (i < n - 1) output_file_py << "; ";
    }
    output_file_py << "')\n";

    output_file_py << "X = inv(A)\n\n";

    output_file_py << "out_file = open(\"output.txt\", \"a\")\n";
    output_file_py << "out_file.write('++++++ P6 BEGIN ++++++\\n')\n";
    output_file_py << "out_file.write('++++++ P6 INVERSION RESULT FROM PYTHON:\\n')\n";
    output_file_py << "\n";
    output_file_py << "for i in range(" << n << "):\n";
    output_file_py << "\tfor j in range(" << n << "):\n";
    output_file_py << "\t\tout_file.write(f'X[{i}][{j}]= {X.item(i,j):.2f} ')\n";
    output_file_py << "\tout_file.write(f'\\n')\n";
    output_file_py << "out_file.write('++++++ P6 END ++++++\\n')\n";
    output_file_py << "out_file.close()\n";

    output_file_py.close();
    system("python3 out_65.py");
}
