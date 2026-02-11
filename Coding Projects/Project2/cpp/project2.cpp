//////////////////////////////////////////////////// PROJECT 2 //////////////////////////////////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_1/sample_p1.h"


using namespace std;

class P2_COURSE:public P1_COURSE{
	// public methods for this class:
	public:  
		P2_COURSE(string, int, int); // constructor;
			// example usage: P2_COURSE C2("EE 259", 4, 3);
			// populates the private data members from the input
			// files of studentInfo.txt and studentGrades.txt;
	
		void P2_REPORT(int, int, int);  // a method;
			// example usage: C2.P2_REPORT(x, y, z);
			// if x is -1, inherit from P1_LIST(y);
			// if x is not -1, for id of x and pin of y, report the grade for exam z;
			// report input error for illegal values of x, y, z;
			// returns no values;
	
		void P2_SORT(void);  // a method;
			// example usage: C2.P2_SORT(void);
			// give the sorted list of students
			// in ascending order based on their ids;
			// returns no values;
	
		int P2_MINMAX(int, int); // a method;
			// example usage: C2.P2_MINMAX(x,y);
			// if x is 0, inherit from P1_MIN(y);
			// if x is 1, find maximum grade for exam y;
			// for any other x or illegal y, input error;
   };

// start constructor code:
P2_COURSE::P2_COURSE(string s, int x, int y)
	:P1_COURSE(s, x, y) // call to instantiate base class
{ 
	// P2_COURSE constructor calls for the constructor of the base class P1_COURSE 
	// and then it does not do anything else;
	// P1_COURSE and P0_COURSE constructors populate the protected data members;
	out_f << "++++++ P2 ++ START ++++" << endl;
	out_f << "++++++ P2 CONSTRUCTOR INSTANTIATED A P2_COURSE OBJECT." << endl;
	out_f << "++++++ P2 ++ END  ++++" << endl;
} // end of constructor

// start P2_REPORT code:
void P2_COURSE::P2_REPORT(int x, int y, int z)
{ 
	// your code goes below:
		
		out_f << "++++++ P2 ++ START OUTPUT FROM P2_REPORT METHOD: " << endl; 
		out_f << "++++++ P2 P2_REPORT IS CALLED WITH x: " << x << ", y: " << y << ", z: " << z << endl;

		if(x==-1) // if x is -1, list all students or an error message
		{
			if(y<0 || y>noof_exams) // check if y is a valid exam number
			{
				out_f << "++++++ P2 INPUT ERROR." << endl;
        		out_f << "++++++ P2 ++ END OUTPUT FROM P2_REPORT METHOD " << endl;
			}
			else
			{
				out_f << "++++++ P2 INHERITING FROM P1_LIST(" << y << "):" << endl;
				P1_LIST(y);
				out_f << "++++++ P2 ++ END OUTPUT FROM P2_REPORT METHOD " << endl; 
			}	
		}
		else if (x != -1) // if x is not -1, find the student's grade
		{
			if (x <0 || x >= 9999 || y <= 0 || y > 9999 || z < 0 || z > noof_exams)
			{
				out_f << "++++++ P2 INPUT ERROR." << endl;
	        	out_f << "++++++ P2 ++ END OUTPUT FROM P2_REPORT METHOD " << endl;
			}
			else
			{
				int studentnumber = P1_FIND(x, y); // find student index 
	        	if (studentnumber == -1) // student not found
	        	{
	            	out_f << "++++++ P2 NO SUCH STUDENT WITH ID " << x << " AND PIN " << y << "." << endl;
	        	}
	        	
	        	else // student found, print the grade
	        	{
	            	out_f << "++++++ P2 THE GRADE OF STUDENT " << id[studentnumber] << " FOR EXAM " << z << " IS " << examGrades[studentnumber][z] << "." << endl;
	        	}
	       	    out_f << "++++++ P2 ++ END OUTPUT FROM P2_REPORT METHOD " << endl;
			}
    	}
} // end of P2_REPORT

// start P2_REPORT code:
void 
P2_COURSE::P2_SORT(void)
{ 
	// your code goes below:
	out_f << "++++++ P2 ++ START OUTPUT FROM P2_SORT METHOD: " << endl; 
	out_f << "++++++ P2 OUTPUT FROM P2_SORT METHOD:" << endl;
	for(int i = 0; i <n; i++)
	{
		int min = id[i]; // assuming current id is the minimum
		int min_pos = i;
		for(int j = i; j < n; j++)
		{
			if (min > id[j]) // find the smallest id
			{
				min = id[j];
				min_pos = j;
			}
			else {}
		}
		// swap the student IDs
		int temp = id[i];
		id[i] = id[min_pos];
		id[min_pos] = temp;

		// swap the student PINs
		temp = pin[i];
		pin[i] = pin[min_pos];
		pin[min_pos] = temp;

		// swap the student exam grades
		for(int k = 0; k < noof_exams; k++)
		{
			temp = examGrades[i][k];
			examGrades[i][k] = examGrades[min_pos][k];
			examGrades[min_pos][k] = temp;
		}
	}
	out_f <<"++++++ P2 ++ END OUTPUT FROM P2_SORT METHOD" << endl;
} // end of P2_SORT

// start P2_MINMAX code:
int 
P2_COURSE::P2_MINMAX(int x, int y)
{ 
	// your code goes below:
	int max;
	if(x==0) // if x is 0, find the minimum grade using parent class method
	{
		out_f << "++++++ P2 ++ START OUTPUT FROM P2_MINMAX METHOD:" << endl;
		out_f << "++++++ P2 P2_MINMAX IS CALLED WITH x: " << x << ", y: " << y << endl;
		out_f << "++++++ P2 INHERITING FROM P1_MIN(" << y << "):" << endl;
		P1_MIN(y);
		out_f << "++++++ P2 ++ END OUTPUT FROM P2_MINMAX METHOD" << endl;
	}
	else if (x==1) // if x is 1, find the maximum grade
	{
		max = examGrades[x][y];
		for(int i = 1; i < n; i++)
		{
			if(examGrades[i][y] > max) // compare grades to find max
			{
				out_f << "++++++ P2 ++ START OUTPUT FROM P2_MINMAX METHOD: " << endl;
				out_f << "++++++ P2 P2_MINMAX IS CALLED WITH x: " << x << ", y: " << y << endl;
				max = examGrades[i][y];
			}
		}
		out_f << "++++++ P2 THE HIGHEST GRADE FOR EXAM " << y << " IS" << max << "." << endl;
		out_f << "++++++ P2 ++ END OUTPUT FROM P2_MINMAX METHOD" << endl;
	}
}
// end of P2_MINMAX code:
