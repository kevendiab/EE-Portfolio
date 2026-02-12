#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctype.h>

using namespace std;

ofstream o_f_8("output_8.txt", ios::out);

class EZ_DIFF_INTEGRATE
{
   public:
    EZ_DIFF_INTEGRATE(char *); // constructor; 
        // example: s.EZ_DIFF_INTEGRATE("in.txt");
        // input data file is given;

    void EZ_DIFF_BY_ME(float, float, int);
        // example: s.EZ_DIFF_BY_ME(a, b, n);
        // differentiate the function defined in input file;
        
    void EZ_INTEG_BY_ME(float, float, int);
        // example: s.EZ_INTEG_BY_ME(a, b, n);
        // integrate the function defined in input file;
        
   private:
    int np; // number of data pairs
    char func_type[10]; // sin, cos, or poly
    int exp; // exponent of sin or cos 
    int arg; // argument to include in function
    int input_error;
};

EZ_DIFF_INTEGRATE::EZ_DIFF_INTEGRATE(char* in_fn)
{
    int m;
    string text;
    ifstream reader(in_fn, ios::in);

    string print_fn = string(in_fn);
    if (print_fn[0] != '/') 
    {
    print_fn = "/mnt/ee259dir/tools/pro_8/" + print_fn;
    }

    o_f_8 << "CONSTRUCTOR WITH INPUT FILE: " << print_fn << endl;
    cout << "CONSTRUCTOR WITH INPUT FILE: " << print_fn << endl;


    if (!reader) 
    {
        input_error = 1;
        return;
    }

    reader >> text;
    if (text == "sin" || text == "cos") 
    {
        strcpy(func_type, text.c_str());
    } 
    else 
    {
        input_error = 1;
        return;
    }

    reader >> text;
    if (text == "(") 
    {
        exp = 1;
    } 
    else if (text == "**") 
    {
        reader >> text;
        exp = atoi(text.c_str());
        reader >> text;
        if (text != "(") 
        {
            input_error = 1;
            return;
        }
    } 
    else 
    {
        input_error = 1;
        return;
    }

    reader >> text;
    arg = atoi(text.c_str());

    for (m = 0; m < 4; m++) 
    {
        reader >> text;
    }

    o_f_8 << "FUNCTION IS PARSED AS: " << func_type << " ** " << exp << " " << arg << "x" << endl;
    cout << "FUNCTION IS PARSED AS: " << func_type << " ** " << exp << " " << arg << "x" << endl;
}

void 
EZ_DIFF_INTEGRATE::EZ_DIFF_BY_ME(float a, float b, int n)
{
    int i, j, k;
    float step = (b - a) / n;
    float points[30], results[30], rates[30];
    int minima = 0, maxima = 0;

    for (i = 0; i <= n; i++) 
    {
        points[i] = a + i * step;
        if (func_type[0] == 's') 
        {
            results[i] = pow(sin(arg * points[i]), exp);
        } 
        else 
        {
            results[i] = pow(cos(arg * points[i]), exp);
        }
    }

    for (j = 0; j < n; j++) 
    {
        rates[j] = (results[j + 1] - results[j]) / step;
    }

    for (k = 0; k < n - 1; k++) 
    {
        if (rates[k] > 0 && rates[k + 1] < 0) 
        {
            o_f_8 << "*** THERE IS AN EXTREME POINT*** df[" << k << "]: " << rates[k] << "\tdf[" << k + 1 << "]: " << rates[k + 1] << endl;
            maxima++;
        } 
        else if (rates[k] < 0 && rates[k + 1] > 0 || rates[k] == 0) 
        {
            o_f_8 << "*** THERE IS AN EXTREME POINT*** df[" << k << "]: " << rates[k] << "\tdf[" << k + 1 << "]: " << rates[k + 1] << endl;
            minima++;
        }
    }

    o_f_8 << "THERE ARE " << minima << " MINIMUMS AND " << maxima << " MAXIMUMS FOR THIS " << func_type << " FUNCTION " << endl;
    o_f_8 << "IN THE INTERVAL OF " << a << " AND " << b << " WITH " << n << " POINTS." << endl;
}

void 
EZ_DIFF_INTEGRATE::EZ_INTEG_BY_ME(float a, float b, int n)
{
    int i;
    float step = (b - a) / n;
    float total = 0;

    for (i = 0; i < n; i++) 
    {
        float x_pt = a + i * step;
        float y_pt = func_type[0] == 's' ? pow(sin(arg * x_pt), exp) : pow(cos(arg * x_pt), exp);
        total = total + fabs(y_pt) * step;
    }

    o_f_8 << "THE INTEGRATION OF THIS " << func_type << " FUNCTION " << endl;
    o_f_8 << "IN THE INTERVAL OF " << a << " AND " << b << " WITH " << n << " POINTS IS " << total << endl;
}

