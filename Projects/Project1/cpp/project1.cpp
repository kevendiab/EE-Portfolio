//////////////////////////////////////////////////////// PROJECT 1 //////////////////////////////////////////////////////////////////////////////////////////


//use diff -w output.txt /mnt/ee259dir/tools/pro_1/out_1_expected_1.txt 

//include "sample_p0.h" not this changed to the bottom one
#include "/mnt/ee259dir/tools/pro_0/sample_p0.h"

// we use an additional file for exam grades:
ifstream input_file_1("studentGrades.txt",ios::in);

class P1_COURSE: public P0_COURSE{
	// public methods for this class:
	public: 

		P1_COURSE(string, int, int);// example: C1.P1_COURSE("EE 59", 4, 5);
						// constructor;
						// instantiate object C1 with name of EE 59, 4 students, 
						// each with 5 exams;

        	void P1_LIST(int);  // example: C1.P1_LIST(x);
                // if x is 0 or 1, inherit from P0_LIST(x);
				// if x is 2, print the exams;
				// if x has any other value, input error;
                // returns no values;

        	int P1_MIN(int);  // example: C1.P1_MIN(x);
                 // find the student(s) with the min grade in exam x and
				// return the index of the student;
				// if x is illegal, input error; return -2;
				// for simplicity, we assume only one student with min or max grade;

        	int P1_FIND(int, int);  // example: b.P1_FIND(x, y);
                // x and y are the id and the pin for a student;
				// if student found, return its index;
                // return -1 if not found;
				// return -2 if input error;

   	protected: // protected variables to be used by this class and classes that
			// may inherit from this class 
		int noof_exams; // number of exams per student;
		int examGrades[20][8]; // grades for max of 20 students for max of 8 exams each;
}; 

// start constructor code:
P1_COURSE::P1_COURSE(string s, int x, int y)
	:P0_COURSE(s, x) // call to instantiate base class using variables s and x 
{
	// x is number of students, y is number of exams:
	int i, j;

	noof_exams = y;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < noof_exams; j++)
		{
			input_file_1 >> examGrades[i][j];
		}
	} 
	out_f << "++++ P1 ++ START ++++" << endl;
	out_f << "++++ P1 CONSTRUCTOR INSTANTIATED A P1_COURSE OBJECT." << endl;
	out_f << "++++ P1 THERE ARE " << noof_exams << " EXAMS." << endl;
	out_f << "++++ P1 ++ END  ++++" << endl;
} // end of constructor


// start P1_LIST code:
void
P1_COURSE::P1_LIST(int x)
{ 
	// your code goes below:
	int i,j;

	if (x == 0 || x==1) // x = 0 OR x = 1
    {
    	if(x==0) //when x = 0 inherit from P0_LIST(0)
    	{
    		out_f << "++++ P1 ++ START OUTPUT FROM P1_LIST METHOD:" << endl;
        	out_f << "++++ P1 ++ INHERITING FROM P0_LIST(0):" << endl;
        	P0_LIST(x);
        	out_f << "++++ P1 ++ END OUTPUT FROM P1_LIST METHOD" << endl;
    	}
    	else if (x==1) //when x = 1 inherit from P0_LIST(1)
    	{
    		out_f << "++++ P1 ++ START OUTPUT FROM P1_LIST METHOD:" << endl;
        	out_f << "++++ P1 ++ INHERITING FROM P0_LIST(1):" << endl;
        	P0_LIST(x);
        	out_f << "++++ P1 ++ END OUTPUT FROM P1_LIST METHOD" << endl;
    	}
        
    }
    
    else if (x == 2) //when x = 2 loop through exam grades and print it out  
    {
        out_f << "++++ P1 ++ START OUTPUT FROM P1_LIST METHOD:" << endl;
        out_f << "++++ P1 ++ INFORMATION FOR EE 159:" << endl;
        for (i = 0; i < n; i++)
        {
            out_f << " STUDENT ID: " << id[i] << " GRADES: ";
            for (j = 0; j < noof_exams; j++)
            {
                out_f << examGrades[i][j] << "  ";
            }
            out_f << endl;
        }
        out_f << "++++ P1 ++ END OUTPUT FROM P1_LIST METHOD" << endl;
    }
    else //if x is any other value ERROR
    {
        out_f << "++++ P1 ++ START OUTPUT FROM P1_LIST METHOD:" << endl;
        out_f << "++++ P1 ++ SINCE P1_LIST IS CALLED WITH " << x << ", INPUT ERROR." << endl;
    	out_f << "++++ P1 ++ END OUTPUT FROM P1_LIST METHOD" << endl;
    }
} // end of P1_LIST code

// start P1_MIN code:
int P1_COURSE::P1_MIN(int x) // x is the exam number
{
	int i;
	
	if (x < 0 || x >= noof_exams) //when x is negative or larger than number of exams its illegal and return -2 
    {
        out_f << "++++ P1 ++ START OUTPUT FROM P1_MIN METHOD:" << endl;
        out_f << "++++ P1 ++ INPUT ERROR. " << endl;
        out_f << "++++ P1 ++ END OUTPUT FROM P1_MIN METHOD" << endl;
        return -2;
    }		

    int min= examGrades[0][x]; // exam grade of student 0 is in the value min as a placeholder
    int index = 0; //index of student with lowest grade

    for (i = 1; i < n; i++)  //for loop through students
    {
        if (examGrades[i][x] < min) // if statement true update min value and index 
        {
            min = examGrades[i][x];
            index = i;
        }
    }
    out_f << "++++ P1 ++ START OUTPUT FROM P1_MIN METHOD: " << endl;
    out_f << "++++ P1 THE LOWEST GRADE FOR EXAM " << x << " IS " << min << "." << endl;
    out_f << "++++ P1 ++ END OUTPUT FROM P1_MIN METHOD" << endl;
    
    return index;

} // end of P1_MIN code

// start P1_FIND code:
int
P1_COURSE::P1_FIND(int x, int y)
{ 
	// your code goes below:
	out_f << "++++ P1 ++ START OUTPUT FROM P1_FIND METHOD:" << endl;
	
	if (x<0 || x>= 99999 || y<0) // if x or y are negative or if x is greater than 99999 its illegal return -2
	{
		out_f << "++++ P1 INPUT ERROR." << endl;
        out_f << "++++ P1 ++ END OUTPUT FROM P1_FIND METHOD" << endl;
		
		return -2;  //return -2 if input error
	}

	for (int i = 0; i<n; i++)
	{
		if (id[i] ==x && pin[i]==y) // if id[i] = x AND pin[i] = y then student is found return index of student 
		{
			out_f << "++++ P1 STUDENT " << x << " IS IN THIS CLASS." << endl;
            out_f << "++++ P1 ++ END OUTPUT FROM P1_FIND METHOD" << endl;

			return i;
		}
	}
	out_f << "++++ P1 NO SUCH STUDENT WITH ID " << x << " AND PIN " << y << "." << endl;
    out_f << "++++ P1 ++ END OUTPUT FROM P1_FIND METHOD" << endl;

    // return -1 if not found
	return -1;
	
} // end of P1_FIND code