//////////////////////////////////////////////////// PROJECT 4 ////////////////////////////////////////////////////////////////////////////////////////////////


#include "/mnt/ee259dir/tools/pro_4/sample_p3.h"

using namespace std;

class P4_COURSE: public P3_COURSE
{
	public:  // public methods for this class
        P4_COURSE(string, int, int); // constructor;
			// example usage: P4_COURSE C41 ("course_name", x, y);
			// x and y are the number of students and exams, respectively;

		bool operator > (int); // a method for an overloaded operator;
			// example usage: if (C41 > x)
			// returns true if the number of students in
			// object C41 is greater than x;
			// returns false otherwise;

		bool operator > (P4_COURSE); // a method for an overloaded operator;
			// example usage: if (C41 > C42)
			// returns true if the number of students in object C41 
			// is greater than the number of students in object C42;
			// returns false otherwise;

		int operator += (P4_COURSE); // a method for an overloaded operator;
			// example usage: C42 += C41;
			// append the students of C41 to C42;
			// C41 remains unchanged;
			// returns the new total number of students in C42;

		int operator -= (int); // a method for an overloaded operator;
			// example usage: C41 -= x;
			// delete the student with id x from C41;
			// returns the new total number of students in C42 if successful;

		int INSERT_STUDENT(string, string, int, int);// a method;
			// example usage: C41.INSERT_STUDENT("MELISA","AYSE",3748, 1111);
			// append the student into the list if the student is not there already;
			// returns the index of the new student if successful;

		void P4_SORT(); // a method;
			// example usage: C41.P4_SORT();
			// sort students in ascending order based on their ids;
			// returns no values;
};

P4_COURSE::P4_COURSE(string c_name, int x, int y)
	:P3_COURSE(c_name, x, y) // call to instantiate base class
{
	// c_name is course name, x is number of students, y is number of exams

//	out_f << "++++++++++ P4 ====== START =====================" << endl;
	out_f << "++++++++++ P4 CONSTRUCTOR INSTANTIATED AN OBJECT NAMED "
			<< c_name << " WITH " << n << " STUDENTS AND " << noof_exams << " EXAMS." << endl;
//	out_f << "++++++++++ P4 THERE ARE " << n << " STUDENTS IN THIS P4_COURSE OBJECT." << endl;
//	out_f << "++++++++++ P4 THERE ARE " << noof_exams << " PROJECTS FOR EACH STUDENT." 
//			<< endl;
//	out_f << "++++++++++ P4 ====== END =======================" << endl;
}

bool 
P4_COURSE::operator > (int x)
{
    if (n > x)
    {
        out_f << "++++++++++ P4 ====== START =====================" << endl;
        out_f << "++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > FOR OBJECT " << courseName << ":" << endl;
        out_f << "++++++++++ P4 EVALUATED TRUE." << endl;
        out_f << "++++++++++ P4 ====== END =======================" << endl;
        return true;
    }
    else
    {
        out_f << "++++++++++ P4 ====== START =====================" << endl;
        out_f << "++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > FOR OBJECT " << courseName << ":" << endl;
        out_f << "++++++++++ P4 EVALUATED FALSE." << endl;
        out_f << "++++++++++ P4 ====== END =======================" << endl;
        return false;
    }
}

bool 
P4_COURSE::operator > (P4_COURSE x)
{
    if (n > x.n)
    {
        out_f << "++++++++++ P4 ====== START =====================" << endl;
        out_f << "++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > FOR OBJECT " << courseName << ":" << endl;
        out_f << "++++++++++ P4 EVALUATED TRUE." << endl;
        out_f << "++++++++++ P4 ====== END =======================" << endl;
        return true;
    }
    else
    {
        out_f << "++++++++++ P4 ====== START =====================" << endl;
        out_f << "++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR > FOR OBJECT " << courseName << ":" << endl;
        out_f << "++++++++++ P4 EVALUATED FALSE." << endl;
        out_f << "++++++++++ P4 ====== END =======================" << endl;
        return false;
    }
}

int 
P4_COURSE::operator += (P4_COURSE x)
{
    int i,index,j;
    
    out_f << "++++++++++ P4 ====== START =====================" << endl;
    out_f << "++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR += FOR OBJECT " << courseName << ":" << endl;
    
    for (i = 0; i < x.n; i++)
    {
        index = P3_INSERT(x.id[i], x.pin[i], x.firstNames[i], x.lastNames[i]);
        if(index!=-1 || index!=-2) 
        {
            for (j = 0; j < noof_exams; j++)
            {
                examGrades[index][j] = x.examGrades[i][j];
            }
        }
    }
    
    out_f << "++++++++++ P4 ====== START =====================" << endl;
    return n;
}

int 
P4_COURSE::operator -=(int x)
{
    int i,index,j;

    index = n;
    out_f << "++++++++++ P4 ====== START =====================" << endl;
    out_f << "++++++++++ P4 OUTPUT FROM OVERLOADED OPERATOR -= FOR OBJECT " << courseName << ":" << endl;
    
    for (i = 0; i < n; i++)
    {
        if (id[i] == x)
        {
            index = i;
        }
    }
    
    if (index != -1)
    {
        out_f << "++++++++++ P4 STUDENT WITH ID " << x << " IS DELETED FROM THIS OBJECT." << endl;
        
        for (i = index; i < n; i++)
        {
            firstNames[i] = firstNames[i+1];
            lastNames[i] = lastNames[i+1];
            id[i] = id[i+1];
            pin[i] = pin[i+1];
              
            for(j = 0; j < noof_exams; j++)
            {
                examGrades[i][j] = examGrades[i+1][j];
            }
        }
        n--;
        out_f << "++++++++++ P4 NOW THERE ARE " << n << " STUDENTS IN OBJECT " << courseName << "." << endl;
    } 
    out_f << "++++++++++ P4 ====== END =======================" << endl;
    return n;
}

int 
P4_COURSE::INSERT_STUDENT(string F, string L, int x, int y)
{
    int r_v;

    out_f << "++++++++++ P4 ====== START =====================" << endl;
    out_f << "++++++++++ P4 OUTPUT FROM P3_INSERT METHOD:" << endl;
    r_v = P3_INSERT(x, y, F, L);
    out_f << "++++++++++ P4 ====== END =======================" << endl;
    return r_v;
}

void 
P4_COURSE::P4_SORT()
{
    out_f << "++++++++++ P4 ====== START =====================" << endl;
    out_f << "++++++++++ P4 OUTPUT FROM P4_SORT METHOD:" << endl;
    P3_ALPHABETIZE();
    out_f << "++++++++++ P4 ====== END =======================" << endl;
}
