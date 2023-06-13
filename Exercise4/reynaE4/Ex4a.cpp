/************************************************************************************************/
/* Program: Ex4a.cpp                                                                            */
/* Author: Alana Reyna                                                                          */
/* Date: 12/18/22                                                                               */
/* Description: Implementation of Exercise 4 part a.                                            */
/************************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include "Bitmap_Image.hpp"
using namespace std;

// Function Prototypes
void DrawLine (bitmap_image & bmp, int x1, int y1, int x2, int y2, int red, int green, int blue);
void DrawLine (bitmap_image & bmp, int x1, int y1, int x2, int y2, int red, int green, int blue);
void DrawRectangle (bitmap_image & bmp, int ulX, int ulY, int width, int height, int red, int green, int blue);
void DrawCircle (bitmap_image & bmp, int centerX, int centerY, int radius, int red, int green, int blue);

/************************************************************************************************/
/* Data structure: Point                                                                        */
/* Description:                                                                                 */
/************************************************************************************************/

struct Point
{
	float x;
	float y;
};

/************************************************************************************************/
/* Prototypes                                                                                   */
/************************************************************************************************/

Point GetPoint (float N, const Point & P1, const Point& P2, const Point & P3);

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
  //ofstream output (argv[2]);
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
  float n, x1, y1, x2, y2, x3, y3;
  input >> n >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  cout << "N: " << n << " x1: " << x1 << " y1: " << y1 << " x2: " << x2 << " y2: " << y2 
  << " x3: " << x3 << " y3: " << y3 << endl;
  
  Point P1;
  P1.x = x1;
  P1.y = y1;

  cout << "P1 x: " << P1.x << " P1 y: " << P1.y << endl;

  Point P2;
  P2.x = x2;
  P2.y = y2;

  cout << "P2 x: " << P2.x << " P2 y: " << P2.y << endl;

  Point P3;
  P3.x = x3;
  P3.y = y3;

  cout << "P3 x: " << P3.x << " P3 y: " << P3.y << endl;

  // Point bezPt = GetPoint(n, P1, P2, P3);
  vector <Point> Curve;
  for (int i = 0; i <= n; i++)
  {
    float percent = float(i) / n;
    Point B = GetPoint (percent, P1, P2, P3);
    cout << "Point B x: " << B.x << " Point B y: " << B.y << endl;
    Curve.push_back(B);
  }
  
  while (input >> action)
    switch (action)
      {
        case 'H': // Set hue (color)
          cout << "set hue" << endl;
          input >> red >> green >> blue;
          break;
        case 'h': // set hue (color)
          cout << "set hue" << endl;
          input >> red >> green >> blue;
          break;
        case 'Z': // Set bitmap size
          cout << "setting bitmap size" << endl;
          input >> width >> height;
          cout << "width: " << width << " height: " << height << endl;
          bitmap.resize (width+1, height+1);
          break;
        case 'z': // set bitmap size
          cout << "setting bitmap size" << endl;
          input >> width >> height;
          cout << "width: " << width << " height: " << height << endl;
          bitmap.resize (width+1, height+1);
          break;
        case 'L': // Draw a line
        {
          int x1, y1, x2, y2;
          input >> x1 >> y1 >> x2 >> y2;
          DrawLine (bitmap, x1, y1, x2, y2, red, green, blue);
          cout << "Draw line" << endl;
        }
        break;
        case 'l': // draw a line
        {
          int x1, y1, x2, y2;
          input >> x1 >> y1 >> x2 >> y2;
          DrawLine (bitmap, x1, y1, x2, y2, red, green, blue);
          cout << "Draw line" << endl;
        }
        break;
        case 'R': // Draw a rectangle
        {
          cout << "drawing rectanle" << endl;
          int x, y, w, h;
          input >> x >> y >> w >> h;
          DrawRectangle (bitmap, x, y, w, h, red, green, blue);
        }
        break;
        case 'r': // draw a rectangle
        {
          cout << "drawing rectanle" << endl;
          int x, y, w, h;
          input >> x >> y >> w >> h;
          DrawRectangle (bitmap, x, y, w, h, red, green, blue);
        }
        break;
        case 'C': // Draw a circle
        {
          cout << "drawing circle" << endl;
          int cx, cy, r;
          input >> cx >> cy >> r;
          DrawCircle (bitmap, cx, cy, r, red, green, blue);
        }
        break;
        case 'c': // Draw a circle
        {
          cout << "drawing circle" << endl;
          int cx, cy, r;
          input >> cx >> cy >> r;
          DrawCircle (bitmap, cx, cy, r, red, green, blue);
        }
        break;
      }
  
  input.close();
  // output.close();
  bitmap.save_image (argv[2]);
  if (bitmap.failed())
    {
      cerr << "Bitmap could not be saved\n";
      exit (4);
    }
  return 0;

}

/************************************************************************************************/
/* Function: GetPoint                                                                           */
/* Arguments:                                                                                   */
/* Description:                                                                                 */
/************************************************************************************************/

Point GetPoint (float percent, const Point & P1, const Point& P2, const Point & P3)
{
  Point A,B,C;

  A.x = P1.x + percent * (P2.x - P1.x);
  A.y = P1.y + percent * (P2.y - P1.y);

  cout << "Point A x: " << A.x << endl;
  cout << "Point A y: " << A.y << endl;

  B.x = P2.x + percent * (P3.x - P2.x);
  B.y = P2.y + percent * (P3.y - P2.y);

  cout << "Point B x: " << B.x << endl;
  cout << "Point B y: " << B.y << endl;

  C.x = A.x + percent * (B.x - A.x);
  C.y = A.y + percent * (B.y - A.y);

  cout << "Point C x: " << C.x << endl;
  cout << "Point C y: " << C.y << endl;

  return C; 
  // // Using P1 and P2 to create first bezier point
  // A.x = P1.x + percent * (P2.x - P1.x);
  // A.y = P1.y + percent * (P2.y - P2.y);

  // // Using P2 and P3 to create second bezier point
  // B.x = P2.x + percent * (P2.x - P3.x);
  // B.y = P2.y + percent * (P2.y - P3.y);

  // // Using Point A and Point B to create third bezier point
  // // C.x = A.x + percent * (B.x - A.x);
  // // C.y = A.y + percent * (B.y - A.y);
  // C.x = A.x + percent * (A.x - B.x);
  // C.y = A.y + percent * (A.y - B.y);

  //return GetPoint(percent, ); 
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
