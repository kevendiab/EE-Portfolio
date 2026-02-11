//////////////////////////////////////////////////// PROJECT 7 ////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "/mnt/ee259dir/tools/pro_6/sample_p6.h"

using namespace std;

ofstream o_f_7("output_7.txt", ios::out);

class EZ_CURVE_FIT: public LINEAR_SOLVER
{
   public:
	EZ_CURVE_FIT(int); // constructor; 
		// example: s.EZ_CURVE_FIT(5);
		// there are 5 pairs of data points;

	void LS_FIT_BY_ME(char *); 
		// example: s.LS_FIT_BY_ME("data_file");
		// perform least squares fit using inheritance 
		// data is in "data_file";
		
	void LS_FIT_BY_MATLAB (char *); 
		// example: s.LS_FIT_BY_MATLAB("data_file);
		// perform least squares fit using MATLAB; 
		
	void LS_FIT_BY_PYTHON (char *); 
		// example: s.LS_FIT_BY_PYTHON("data_file);
		// perform least squares fit using Python; 
   private:
	int np; // number of data pairs
};

EZ_CURVE_FIT::EZ_CURVE_FIT(int x) 
    :LINEAR_SOLVER(2) 
{
    np = x;
    o_f_7 << "++++++++ P7 BEGIN ++++++" << endl;
    o_f_7 << "++++++++ P7 INSTANTIATED AN OBJECT WITH " << np << " DATA POINTS" << endl;
    o_f_7 << "++++++++ P7 END ++++++" << endl;
}


void EZ_CURVE_FIT::LS_FIT_BY_ME(char *data_file) 
{
    int i;
    float x_array[15], y_array[15];
    float sum_of_x_squared = 0, sum_of_x = 0, sum_of_xy = 0, sum_of_y = 0;
    float calculated_slope, calculated_intercept, total_squared_error = 0;
    string temp;


    ifstream input(data_file);
    for (i = 0; i < np; ++i) 
    {
        input >> x_array[i] >> y_array[i];
        sum_of_x_squared += x_array[i] * x_array[i];
        sum_of_x  += x_array[i];
        sum_of_xy += x_array[i] * y_array[i];
        sum_of_y  += y_array[i];
    }

    ofstream matrix("S_values.txt");
    matrix << sum_of_x_squared << " " << sum_of_x << endl;
    matrix << sum_of_x  << " " << np << endl;
    matrix << sum_of_xy << endl;
    matrix << sum_of_y  << endl;

    LINEAR_SOLVER solver("S_values.txt", 2);
    solver.SOLVE_LINEAR_EQUATION("UNSORTED");

    ifstream output("output.txt");
    for (i = 0; i < 12; ++i) getline(output, temp);
    output >> temp >> calculated_slope >> temp >> calculated_intercept;

    o_f_7 << "LEAST_SQUARE_FIT RESULT:" << endl;
    o_f_7 << "USING INHERITANCE:" << endl;
    o_f_7 << "MATCHING FUNCTION IS Y = " << fixed << setprecision(2) << calculated_slope << " * X + " << calculated_intercept << endl;

    for (i = 0; i < np; ++i) 
    {
        float predicted = calculated_slope * x_array[i] + calculated_intercept;
        total_squared_error += pow((y_array[i] - predicted), 2);
    }

    o_f_7 << "THE ERROR FROM LS_FIT_BY_ME METHOD IS " << fixed << setprecision(3) << total_squared_error << endl;
}

void EZ_CURVE_FIT::LS_FIT_BY_MATLAB(char *file_name) 
{
    int i;
    float x_array_for_matlab[50], y_array_for_matlab[50];
    ifstream inData(file_name);

    for (i = 0; i < np; ++i) 
    {
        inData >> x_array_for_matlab[i] >> y_array_for_matlab[i];
    }

    ofstream mat_file("mat_1.m");
    mat_file << "x=[";
    for (i = 0; i < np; ++i) 
    {
        mat_file << x_array_for_matlab[i];
        if (i < np - 1) mat_file << ", ";
    }
    mat_file << "];" << endl;

    mat_file << "y=[";
    for (i = 0; i < np; ++i) 
    {
        mat_file << y_array_for_matlab[i];
        if (i < np - 1) mat_file << ", ";
    }
    mat_file << "];" << endl;
    mat_file << "coef=polyfit(x,y,1);" << endl;
    mat_file << "m=coef(1);" << endl;
    mat_file << "b=coef(2);" << endl;
    mat_file << "Y=m*x+b;" << endl;
    mat_file << "matlab_error=sum((y - Y).^2);" << endl;
    mat_file << "fid=fopen('output_7.txt','a');" << endl;
    mat_file << "fprintf(fid,'*** RESULT FROM MATLAB\\n');" << endl;
    mat_file << "fprintf(fid,'*** THE MATCHING FUNCTION IS Y=(%.3f) * X +(%.3f) \\n',m,b);" << endl;
    mat_file << "fprintf(fid,'*** THE ERROR FROM MATLAB IS %.3f \\n', matlab_error);" << endl;

    system("/bin/csh /mnt/ee259dir/tools/pro_7/run_mat_1");
}


void EZ_CURVE_FIT::LS_FIT_BY_PYTHON(char *file_name) 
{
    int i;
    float x_array_for_python[50], y_array_for_python[50];
    ifstream data(file_name);

    for (i = 0; i < np; ++i) 
    {
        data >> x_array_for_python[i] >> y_array_for_python[i];
    }

    ofstream python_script("my_python_7.py");
    python_script << "import numpy as np" << endl;
    python_script << "" << endl;
    python_script << "x = np.array([";
    for (i = 0; i < np; ++i) 
    {
        python_script << x_array_for_python[i];
        if (i < np - 1) python_script << ",";
    }
    python_script << "])" << endl;

    python_script << "y = np.array([";
    for (i = 0; i < np; ++i) 
    {
        python_script << y_array_for_python[i];
        if (i < np - 1) python_script << ",";
    }
    python_script << "])" << endl;
    python_script << "coef = np.polyfit(x,y,1)" << endl;
    python_script << "m = coef[0]" << endl;
    python_script << "b = coef[1]" << endl;
    python_script << "Y = m * x + b" << endl;
    python_script << "python_error = np.sum((y - Y) ** 2)" << endl;
    python_script << "" << endl;
    python_script << "fid = open('./output_7.txt','a')" << endl;
    python_script << "fid.write(\"*** RESULT FROM PYTHON\\n\")" << endl;
    python_script << "fid.write(f\"*** THE MATCHING FUNCTION IS Y=({m:.3f}) * X +({b:.3f}) \\n\")" << endl;
    python_script << "fid.write(f\"*** THE ERROR FROM PYTHON IS {python_error:.3f}\\n\")" << endl;
    python_script << "fid.close()" << endl;

    system("python3 my_python_7.py");
}
