//////////////////////////////////////////////////// PROJECT 3 ////////////////////////////////////////////////////////////////////////////////////////////////

#include "/mnt/ee259dir/tools/pro_2/sample_p2.h"

using namespace std;

// declare the input file for first and last names;
ifstream input_file_3("studentNames.txt",ios::in);

class P3_COURSE:public P2_COURSE{
	// public methods for this class:
	public:  
		P3_COURSE(string, int, int); // constructor;
			// example usage: P3_COURSE C3("EE 359", 4, 3);
			// populates the private data members from the input
			// files of studentInfo.txt, studentGrades.txt and
			// studentNames.txt;
	
		void P3_LIST_ALL(); // a method;
			// example usage: C3.P3_LIST_ALL();
			// list all students and grades

		void P3_ALPHABETIZE();  // a method;
			// example usage: C3.P3_ALPHABETIZE();
			// sort students in alphabetical order based on their 
			// last names (all last names are unique for simplicity);
			// returns no values;

		int P3_INSERT(int, int, string, string);  // a method;
			// example usage: C3.P3_INSERT(x, y, F, L);
			// first check if student exists by P1_FIND(x,y);
			// if P1_FIND returns -1, then insert a new student with id x, 
			// pin y, first name F and last name L;
			// set the grades for the new student to 0;
			// if successful, return the new student index;
			// return -1 if student exists;
			// return -2 if any of the input parameters is illegal;

		int P3_UPDATE(int, int, int, int);  // a method;
			// example usage: C3.P3_UPDATE(x, y, z, e);
			// for a student with id of x and pin of y, 
			// first check if student exists by P1_FIND(x,y);
			// if P1_FIND returns -1, then update exam z grade as e; 
			// if successful, return the student index;
			// return -1 if student does not exist;
			// return -2 if any of the input parameters is illegal;

   protected: // protected vars to be used by this class and classes that
		// that inherit from this class only (not from main)
        string firstNames[20]; // first names for 20 students; 
        string lastNames[20]; // last names for 20 students;
};

// start constructor code:
P3_COURSE::P3_COURSE(string s, int x, int y)
	:P2_COURSE(s, x, y) // call to instantiate base class
{ 
	// P3_COURSE constructor calls for the constructor of the base class 
	// of P2_COURSE; then it populates the firstNames and lastNames arrays 
	// from studentNames.txt file;

	int i;

	// read first and last names from studentNames.txt file:
	for(i = 0; i < n; i++)
	{
		input_file_3 >> firstNames[i] >> lastNames[i];
	} 

	out_f << "++++++++ P3 ++ START ++++" << endl;
	out_f << "++++++++ P3 THERE ARE " << x << " STUDENTS IN THIS P3_COURSE OBJECT." 
		<< endl;
	out_f << "++++++++ P3 THERE ARE " << y << " EXAMS FOR EACH STUDENT." << endl;
	out_f << "++++++++ P3 ++ END  ++++" << endl;
} // end of constructor


// start P3_LIST_ALL code:
void
P3_COURSE::P3_LIST_ALL(void)
{	
	// your code goes below:
	int i,j;

	out_f << "++++++++ P3 ++ START OUTPUT FROM P3_LIST_ALL METHOD: " << endl;

	// loop through all students and print their information
	for (i = 0; i < n; i++)
	{
		out_f << "++++++++ P3 " << firstNames[i] << "\t" << lastNames[i] << "\t"; 
		for (j = 0; j < noof_exams; j++)
		{
			out_f << examGrades[i][j] << " ";
		}
		out_f << endl;
	}
	out_f << "++++++++ P3 ++ END OUTPUT FROM P3_LIST_ALL METHOD" << endl;

	
} // end of P3_LIST_ALL

// start P3_ALPHABETIZE code:
void
P3_COURSE::P3_ALPHABETIZE()
{	
	// your code goes below:

	//sort students alphabetically by last name
	out_f << "++++++++ P3 ++ START OUTPUT FROM P3_ALPHABETIZE METHOD: " << endl;
	int i,j;
	int minindex = 0;
	for(i =0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(lastNames[j]< lastNames[i]) // if a smaller last name is found
			{
				minindex = j; // update the minimum index
			}
		}
		swap(lastNames[i],lastNames[minindex]); // swap student last names
		swap(firstNames[i],firstNames[minindex]); // swap student first names
		swap(id[i], id[minindex]); // swap ID's
		swap(pin[i],pin[minindex]); // swap pins 
		for(int k =0;k<noof_exams;k++)
		{
			swap(examGrades[i][k], examGrades[minindex][k]); //swap exam grades
		}
	}
	out_f<< "++++++++ P3 ++ END OUTPUT FROM P3_ALPHABETIZE METHOD" <<endl;
}
// end of P3_ALPHABETIZE

// start P3_INSERT code:
int
P3_COURSE::P3_INSERT(int x, int y, string F, string L)
{
	// your code goes below:
	// insert a new student if they don’t already exist
	out_f<< "++++++++ P3 ++ START OUTPUT FROM P3_INSERT METHOD: "<<endl;
	out_f<< "++++++++ P3 P3_INSERT IS CALLED WITH x: "<< x <<", y: "<< y <<", first name: "<< F << ", last name: " << L<<endl;

	if(x<0 || y>99999 || y<0 || F.empty() || L.empty())
	{
		out_f<< "++++++++ P3 INPUT ERROR."<<endl;
		out_f<< "++++++++ P3 ++ END OUTPUT FROM P3_INSERT METHOD"<<endl;
		return -2; // return error code for invalid input
	}
	out_f<< "++++++++ P3 INVOKING P1_FIND(" << x << "," << y << "):"<<endl;

	int find = P1_FIND(x,y); // check if student already exists
	
	if(find != -1)
	{
		out_f << "++++++++ P3 STUDENT IS ALREADY IN THIS OBJECT:" << endl;
    	out_f << "++++++++ P3 LAST NAME: " << lastNames[find] << " FIRST NAME: " << firstNames[find] << " ID: " << x << endl;
    	out_f << "++++++++ P3 THERE ARE STILL " << n << " STUDENTS IN THIS OBJECT" << endl;
    	out_f<< "++++++++ P3 ++ END OUTPUT FROM P3_INSERT METHOD"<<endl;

		return -1; // return error code meaning there is a duplicate student
	}

	else if(find == -1)
	{
		id[n]= x; //store ID
		pin[n]=y; //store PIN
		firstNames[n] = F; //store first names
		lastNames[n] = L;  //store last names
		for(int j=0;j<noof_exams;j++)
		{
			examGrades[n][j] = 0;
		}
		n++;
		int updatednos = n;

		out_f<< "++++++++ P3 NEW STUDENT ADDED TO THIS OBJECT:"<<endl;
		out_f<< "++++++++ P3 LAST NAME: "<< L << " FIRST NAME: "<< F <<" ID: "<< x <<endl;
		out_f<< "++++++++ P3 NOW THERE ARE " << updatednos<< " STUDENTS IN THIS OBJECT."<<endl;

		out_f<< "++++++++ P3 ++ END OUTPUT FROM P3_INSERT METHOD"<<endl;

		return updatednos; // return updated number of students

	}
	
}
// end of P3_INSERT


// start of P3_UPDATE code:
int
P3_COURSE::P3_UPDATE(int x, int y, int z, int w)
{
	// your code goes below:

	// updates a student's exam grade

	out_f<< "++++++++ P3 ++ START OUTPUT FROM P3_UPDATE METHOD:"<<endl;
	out_f<< "++++++++ P3 P3_UPDATE IS CALLED WITH x: " <<x<< ", y: " <<y<<", z: "<<z<<", w: "<<w<<endl;

	if(x<0 || y>99999 || y<0 || z>=noof_exams || z<0 || w<0 || w>100)
	{
		out_f<< "++++++++ P3 INPUT ERROR."<<endl;
		out_f<< "++++++++ P3 ++ END OUTPUT FROM P3_UPDATE METHOD"<<endl;
		return -2; // return error code for invalid input
	}
	out_f<< "++++++++ P3 INVOKING P1_FIND("<<x<<","<<y<<"):"<<endl;
	int find = P1_FIND(x,y);
	if(find == -1)
	{
		out_f<< "++++++++ P3 NO SUCH STUDENT WITH ID "<<x<<" AND PIN "<< y<< "."<<endl;

    	out_f << "++++++++ P3 ++ END OUTPUT FROM P3_UPDATE METHOD" << endl;
		return -1; // return error code for missing student
	}
	else if(find != -1)  // if student does not exist
	{
    	examGrades[find][z] = w; // update exam grade
    	out_f<< "++++++++ P3 FOR STUDENT ID "<< x <<" EXAM "<< z<<" GRADE IS SET TO  "<< w <<"."<<endl;

    	out_f << "++++++++ P3 ++ END OUTPUT FROM P3_UPDATE METHOD" << endl;
	}
    

	return find; // return index of updated student
}
// end of P3_UPDATE