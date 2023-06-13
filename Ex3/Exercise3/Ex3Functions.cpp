/************************************************************************************************/
/* Program: Exercise 3 Graphics Program                                                         */
/* File: Ex3Functions.cpp                                                                       */
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
#include <cmath>
#include "Bitmap_Image.hpp"
#include "Ex3Functions.h"
using namespace std;

/************************************************************************************************/
/* Function: DrawLine                                                                           */
/* Arguments:                                                                                   */
/* Description:                                                                                 */
/************************************************************************************************/

void DrawLine (bitmap_image & bmp, int x1, int y1, int x2, int y2, int red, int green, int blue)
{
	bmp.set_pixel (x1, y1, red, green, blue);
	bmp.set_pixel (x2, y2, red, green, blue);
}

/************************************************************************************************/
/* Function: DrawRectangle                                                                      */
/* Arguments:                                                                                   */
/* Description:                                                                                 */
/************************************************************************************************/

void DrawRectangle (bitmap_image & bmp, int ulX, int ulY, int width, int height, int red, int green, int blue)
{
}

/************************************************************************************************/
/* Function: DrawCircle                                                                         */
/* Arguments:                                                                                   */
/* Description:                                                                                 */
/************************************************************************************************/

void DrawCircle (bitmap_image & bmp, int centerX, int centerY, int radius, int red, int green, int blue)
{
}

/************************************************************************************************/
/* Function: DrawEllipse                                                                        */
/* Arguments:                                                                                   */
/* Description:                                                                                 */
/************************************************************************************************/

void DrawEllipse (bitmap_image & bmp, int centerX, int centerY, int radiusX, int radiusY, int red, int green, int blue)
{
}

