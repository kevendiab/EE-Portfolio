//////////////////////////////////////////////////////// PROJECT 0 //////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream input_file_0; // declare a pointer to an input file 
ofstream out_f("output.txt",ios::out); // declare the output file

class P0_COURSE{
   public:      // public methods for this class

		P0_COURSE(string, int); // example: b.P0_COURSE("EE59", 4);
			// constructor;
			// populates the private data members from the 
			// data read from the input file called studentInfo.txt;

		void P0_LIST(int);  // example: b.P0_LIST(x);
			// if x is 0, give the course information;
			// if x is 1, give more information;
			// if x has any other value, input error;
			// returns no values;

	protected: // private var to be used by this class and allows for
			// other classes inherit from this class;

		int n;  // noof students
		string courseName; // string to keep the course name;
		int id[20]; // the integer array to hold the student ids
		int pin[20]; // the integer array to hold the pin numbers
};

// start constructor code:
P0_COURSE::P0_COURSE(string x, int y)
{
	int i;
	// x is the course name
	courseName = x;
	// y is number of students
	n = y;

	input_file_0.open("studentInfo.txt", ios::in); // open input file;

        for(i=0; i<n; i++)
        {
			input_file_0 >> id[i] >> pin[i];
        }

	input_file_0.close(); // close input file;
	input_file_0.clear(); // rewind file pointer to the top of the file;

	// debugging print statement: prints on the terminal screen; 
	for(i = 0; i < n; i++) 
	{ 
		cout << "IN P0: id[" << i << "] " << id[i] << " pin[" << i << "] " << pin[i] << endl; 
	}
	out_f << "++ P0 ++ START ++++" << endl;
	out_f << "++ P0 CONSTRUCTOR SUCCESSFULLY INSTANTIATED A P0_COURSE OBJECT." << endl;
	out_f << "++ P0 NAME OF THE COURSE IS " << courseName << "." << endl;
	out_f << "++ P0 THERE ARE " << n << " STUDENTS IN THIS P0_COURSE OBJECT." << endl;
	out_f << "++ P0 ++ END  ++++" << endl;
} // end of constructor

// start P0_LIST code:
void P0_COURSE::P0_LIST(int x)
{ 
	// your code goes here:
	int i;
	if (x==0)
	{
		out_f << "++ P0 ++ START OUTPUT FROM P0_LIST METHOD:" << endl;
		out_f << "++ P0 THE COURSE IS " << courseName << " WITH " << n << " STUDENTS." << endl;
		out_f << "++ P0 ++ END OUTPUT FROM P0_LIST METHOD." << endl;
	}	

	else if (x==1)
	{
		out_f << "++ P0 ++ START OUTPUT FROM P0_LIST METHOD:" << endl;
		out_f << "++ P0 THE COURSE IS " << courseName << " WITH " << n << " STUDENTS." << endl;
		for(i = 0; i < n; i++) 
		{
			out_f << "++ P0 " << id[i] << endl;
		}
		out_f << "++ P0 ++ END OUTPUT FROM P0_LIST METHOD." << endl;	
	}
	
	else 
	{
		out_f << "++ P0 ++ START OUTPUT FROM P0_LIST METHOD:" << endl;
		out_f << "++ P0 SINCE P0_LIST IS CALLED WITH " << x << ", INPUT ERROR." << endl;
		out_f << "++ P0 ++ END OUTPUT FROM P0_LIST METHOD." << endl;

	}
} // end of P0_LIST code
