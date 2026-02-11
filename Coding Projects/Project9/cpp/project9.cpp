//////////////////////////////////////////////////// PROJECT 9 ////////////////////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <fstream>
#include <string.h>
#include <thread>
using namespace std;

// global variables
ofstream out_f ("output_9.txt", ios::out);
int result[400];
int result_x[400];
int result_y[400];
int image[20][20]; // image file;
int filter[5][5]; // filter file;

#include "thread.h"

class IMAGE_PROC{
	public:	// public methods for this class
	  IMAGE_PROC (int, char *, int, char *);  // constructor;
			// example: IMAGE_PROC A1(20, "image_num.txt", 3, "filter_num.txt");
			// creates object A1 for a 20x20 image and a 3x3 filter;
  
	  void PRINT(char *);	// example: A1.PRINT("ALL");
			// print the elements of image, filter or both;
			// returns no values;

	  void COUNT(); // example: A1.COUNT();
			// find number of occurrences of filter in image data;
			// returns no values;
	
	  void LOCATE(); // example: A1.LOCATE();
			// report locations of filter occurrences in image data;
			// returns no values;

	private:
  	  int n;	// dimension of image file;
	  int f;	// dimension of filter image;
	  char im_file[20]; // name of image file;
	  char filt_file[20]; // name of filter file;
 };

IMAGE_PROC::IMAGE_PROC (int x, char * f1, int y, char * f2)  // constructor;
{
	int i, j;

	n = x;
	f = y;
	strcpy(im_file, f1);
	strcpy(filt_file, f2);
	ifstream im_f(f1, ios::in);
	ifstream filt_f(f2, ios::in);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			im_f >> image[i][j];
		}
	}

	for(i = 0; i < f; i++)
	{
		for(j = 0; j < f; j++)
		{
			filt_f >> filter[i][j];
		}
	}
	// your output messages from constructor here:

	out_f << "+++ P9 START +++++++++++++++++++++++++++++++++++++++++" << endl;
    out_f << "+++ P9_OUTPUT >>> CREATED AN IMAGE_PROC OBJECT" << endl;
    out_f << "+++ P9_OUTPUT >>> IMAGE FILE IS " << im_file << " WITH SIZE OF " << n << " X " << n << endl;
    out_f << "+++ P9_OUTPUT >>> FILTER FILE IS " << filt_file << " WITH SIZE OF " << f << " X " << f << endl;
    out_f << "+++ P9 END +++++++++++++++++++++++++++++++++++++++++++" << endl;

}

void 
IMAGE_PROC::PRINT(char *cmd)
{
    int r, c;

    out_f << "+++ P9 START +++++++++++++++++++++++++++++++++++++++++" << endl;

    if
    (
        strcmp(cmd, "IMAGE") == 0 || strcmp(cmd, "ALL") == 0
    )
    {
        out_f << "+++ P9_OUTPUT >>> IMAGE IS:" << endl;
        for (r = 0; r < n; r++)
        {
            for (c = 0; c < n; c++)
            {
                out_f << image[r][c] << " ";
            }
            out_f << endl;
        }
    }

    if
    (
        strcmp(cmd, "FILTER") == 0 || strcmp(cmd, "ALL") == 0
    )
    {
        out_f << "+++ P9_OUTPUT >>> FILTER IS:" << endl;
        for (r = 0; r < f; r++)
        {
            for (c = 0; c < f; c++)
            {
                out_f << filter[r][c] << " ";
            }
            out_f << endl;
        }
    }

    out_f << "+++ P9 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void 
IMAGE_PROC::COUNT()
{
    int r, c;

    out_f << "+++ P9 START +++++++++++++++++++++++++++++++++++++++++" << endl;

    int total = 0;
    int threadCount = (n - f + 1) * (n - f + 1);
    thread threadList[threadCount];

    int tid = 0;
    for (r = 0; r <= n - f; r++)
    {
        for (c = 0; c <= n - f; c++)
        {
            threadList[tid] = thread(call_from_thread, tid, r, c, n, f);
            tid++;
        }
    }

    for (int i = 0; i < threadCount; i++)
    {
        threadList[i].join();
    }

    for (int i = 0; i < threadCount; i++)
    {
        total += result[i];
    }

    out_f << "+++ P9_OUTPUT >>> THERE ARE " << total << " MATCHES OF FILTER IN IMAGE." << endl;
    out_f << "+++ P9 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void 
IMAGE_PROC::LOCATE()
{
    int r, c,m;

    out_f << "+++ P9 START +++++++++++++++++++++++++++++++++++++++++" << endl;

    int threadCount = (n - f + 1) * (n - f + 1);
    thread threads[threadCount];

    int idx = 0;
    for (r = 0; r <= n - f; r++)
    {
        for (c = 0; c <= n - f; c++)
        {
            threads[idx] = thread(call_from_thread, idx, r, c, n, f);
            idx++;
        }
    }

    for (int k = 0; k < threadCount; k++)
    {
        threads[k].join();
    }

    int found = 0;
    for (m = 0; m < threadCount; m++)
    {
        if
        (
            result[m] == 1
        )
        {
            found++;
        }
    }

    out_f << "+++ P9_OUTPUT >>> THERE ARE " << found << " MATCHES OF FILTER IN IMAGE AS FOLLOWS:" << endl;
    for (m = 0; m < threadCount; m++)
    {
        if
        (
            result[m] == 1
        )
        {
            out_f << "+++ P9_OUTPUT >>> MATRIX LOCATION [" << result_x[m] << "," << result_y[m] << "]" << endl;
        }
    }

    out_f << "+++ P9 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}