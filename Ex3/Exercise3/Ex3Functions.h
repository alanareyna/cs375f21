/************************************************************************************************/
/* Program: Exercise 3 Graphics Program                                                         */
/* File: Ex3Functions.h                                                                         */
/* Author: Dr. Watts                                                                            */
/* Date: 1 September 2021                                                                       */
/* Modified by:                                                                                 */
/* Date:                                                                                        */
/* Description: This program will read shape parameters from an input file and will create      */
/*              a bitmap file illustrating the shapes.                                          */
/*              This file contains                                                              */
/************************************************************************************************/

// Function Prototypes

void DrawLine (bitmap_image & bmp, int x1, int y1, int x2, int y2, int red, int green, int blue);
void DrawRectangle (bitmap_image & bmp, int ulX, int ulY, int width, int height, int red, int green, int blue);
void DrawCircle (bitmap_image & bmp, int centerX, int centerY, int radius, int red, int green, int blue);
void DrawEllipse (bitmap_image & bmp, int centerX, int centerY, int radiusX, int radiusY, int red, int green, int blue);
