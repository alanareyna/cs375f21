/************************************************************************************************/
/* Program: Exercise 3 Graphics Program                                                         */
/* File: Ex3Functions.cpp                                                                       */
/* Author: Dr. Watts                                                                            */
/* Date: 1 September 2021                                                                       */
/* Modified by: Alana Reyna                                                                     */
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
/* Arguments: x1, y1, x2, and y2 are the endpoints of the line. Red, green, and blue are the    */
/*   line colors                                                                                */
/* Description: draws a line from the two endpoints                                             */
/************************************************************************************************/

void DrawLine (bitmap_image & bmp, int x1, int y1, int x2, int y2, int red, int green, int blue)
{
  float rise = y2 - y1;
        float run = x2 - x1;
        float m = rise / run;
        float b = y1 - m * x1;

        if (x1 == x2) {
          if (y1 > y2) {
            for (int z = y1; z >= y2; z--){
              int y = z;
              bmp.set_pixel (x1, y, red, green, blue);
              bmp.set_pixel (x2, y, red, green, blue);
            }
          }
          else if (y1 < y2){
            for (int z = y1; z <= y2; z++){
              int y = z;
              bmp.set_pixel (x1, y, red, green, blue);
              bmp.set_pixel (x2, y, red, green, blue);
            }
          }
        }
        else if (abs(run) >= abs(rise)) {
          if (x1 < x2){
            for (int x = x1; x <= x2; x++){
              int y = m * x + b + 0.5;
              bmp.set_pixel (x, y, red, green, blue);
              bmp.set_pixel (x, y, red, green, blue);
            }
          }
          else {
            for (int x = x1; x >= x2; x--) {
              int y = m * x + b + 0.5;
              bmp.set_pixel (x, y, red, green, blue);
              bmp.set_pixel (x, y, red, green, blue);
            }
          }
        }
	else if (abs(rise) >= abs(run)){
          if (y1 < y2) {
            for (int y = y1; y <= y2; y++){
              int x = (y - b) / m + 0.5;
              bmp.set_pixel (x, y, red, green, blue);
              bmp.set_pixel (x, y, red, green, blue);
            }
          }
          else {
            for (int y = y1; y >= y2; y--) {
              int x = (y - b) / m + 0.5;
              bmp.set_pixel (x, y, red, green, blue);
              bmp.set_pixel (x, y, red, green, blue);
            }
          }
        }

        else if (x1 > x2) {
          for (int x = x1; x <= x2; x--){
            int y = m * x + b + 0.5;
            bmp.set_pixel (x, y, red, green, blue);
            bmp.set_pixel (x, y, red, green, blue);
          }
        }

}

/************************************************************************************************/
/* Function: DrawRectangle                                                                      */
/* Arguments: ulX(upper left x), ulY(upper left y), width, and height                           */
/* Description: draws a rectangle using the upper left x and y points, width, and height        */
/************************************************************************************************/

void DrawRectangle (bitmap_image & bmp, int ulX, int ulY, int width, int height, int red, int green, int blue)
{

  int ulX2 = ulX + width;
  int ulY2 = ulY;
  int ulX3 = ulX2;
  int ulY3 = ulY2 + height;
  int ulX4 = ulX;
  int ulY4 = ulY3;

  DrawLine(bmp, ulX, ulY, ulX2, ulY2, red, green, blue);
  DrawLine(bmp, ulX2, ulY2, ulX3, ulY3, red, green, blue);
  DrawLine(bmp, ulX3, ulY3, ulX4, ulY4, red, green, blue);
  DrawLine(bmp, ulX4, ulY4, ulX, ulY, red, green, blue); 
}

/************************************************************************************************/
/* Function: DrawCircle                                                                         */
/* Arguments: centerX, centerY, and radius                                                      */
/* Description: uses a for loop with x starting at the -radius and incrementing 1 until it      */
/* reaches radius. +- of Y is found using the square root of radius + x times radius + x        */
/************************************************************************************************/

void DrawCircle (bitmap_image & bmp, int centerX, int centerY, int radius, int red, int green, int blue)
{
  //bmp.set_pixel(centerX, centerY, 0, 0, 0);
  float prevX = centerX - radius;
  float prevY1 = centerY;
  float prevY2 = centerY;
  for(float x = -radius; x <= radius; x++){
    float y = sqrt((radius + x)*(radius - x));
    DrawLine(bmp, prevX, prevY1, x+centerX, centerY + y, red, green, blue);
    DrawLine(bmp, prevX, prevY2, x+centerX, centerY - y, red, green, blue);
    prevX = x + centerX;
    prevY1 = centerX + y;
    prevY2 = centerX - y;
  }
  
}

/************************************************************************************************/
/* Function: DrawEllipse                                                                        */
/* Arguments: bmp, centerX, centerY, radiusX, radiusY, red, green, and blue                     */
/* Description: similar to DrawCircle. I create a previous x and y point that we will use to    */
/* draw a line from the previus to the next x and y value                                       */
/************************************************************************************************/

void DrawEllipse (bitmap_image & bmp, int centerX, int centerY, int radiusX, int radiusY, int red, int green, int blue)
{
  bmp.set_pixel(centerX, centerY, 0, 0, 0);
  float prevX = centerX - radiusX;
  float prevY1 = centerY;
  float prevY2 = centerY;
  for(float x = -radiusX; x <= radiusX; x++){
    float y = (radiusY * sqrt((radiusX + x)*(radiusX - x))) / radiusX;
    DrawLine(bmp, prevX, prevY1, x+centerX, centerY + y, red, green, blue);
    DrawLine(bmp, prevX, prevY2, x+centerX, centerY - y, red, green, blue);
    prevX = x + centerX;
    prevY1 = centerY + y;
    prevY2 = centerY - y;
  }
}

