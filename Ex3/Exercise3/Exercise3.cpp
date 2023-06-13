/************************************************************************************************/
/* Program: Exercise 3 Graphics Program                                                         */
/* File: Exercise3.cpp                                                                          */
/* Author: Dr. Watts                                                                            */
/* Date: 1 September 2021                                                                       */
/* Modified by:                                                                                 */
/* Date:                                                                                        */
/* Description: This program will read shape parameters from an input file and will create      */
/*              a bitmap file illustrating the shapes.                                          */
/*              This file contains                                                              */
/************************************************************************************************/

#include <iostream>
#include <fstream>
#include "Bitmap_Image.hpp"
#include "Ex3Functions.h"
using namespace std;

/************************************************************************************************/
/* Function: main                                                                               */
/* Arguments:                                                                                   */
/* Description:                                                                                 */
/************************************************************************************************/

int main (int argc, char * argv [])
{
	if (argc < 3)
	{
		cerr << "Usage: " << argv[0] << " <input_file> <bitmap_file>\n";
		exit (1);
	}
	ifstream input (argv[1]);
	if (input.fail())
	{
		cerr << "File: " << argv[1] << " cannot be opened.\n";
		exit (2);
	}
	char action;
	int width = 100, height = 100;
	int red = 0, green = 0, blue = 0;
	bitmap_image bitmap = bitmap_image (width+1, height+1);
	if (bitmap.failed())
	{
		cerr << "Bitmap could not be created\n";
		exit (3);
	}
	bitmap.clear(0xFF);
	while (input >> action)
		switch (action)
		{
			case 'H': // Set hue (color)
				input >> red >> green >> blue;
				break;
			case 'Z': // Set bitmap size
				input >> width >> height;
				bitmap.resize (width+1, height+1);
				break;
			case 'L': // Draw a line
			{
				int x1, y1, x2, y2;
				input >> x1 >> y1 >> x2 >> y2;
				DrawLine (bitmap, x1, y1, x2, y2, red, green, blue);
			}
			break;
			case 'R': // Draw a rectangle
			{
				int x, y, w, h;
				input >> x >> y >> w >> h;
				DrawRectangle (bitmap, x, y, w, h, red, green, blue);
			}
			break;
			case 'C': // Draw a circle
			{
				int cx, cy, r;
				input >> cx >> cy >> r;
				DrawCircle (bitmap, cx, cy, r, red, green, blue);
			}
			break;
			case 'E': // Draw an ellipse
			{
				int cx, cy, rx, ry;
				input >> cx >> cy >> rx >> ry;
				DrawEllipse (bitmap, cx, cy, rx, ry, red, green, blue);
			}
			break;
		}
	input.close();
	bitmap.save_image (argv[2]);
	if (bitmap.failed())
	{
		cerr << "Bitmap could not be saved\n";
		exit (4);
	}
	return 0;
}
