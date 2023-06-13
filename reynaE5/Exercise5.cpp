/********************************************************************************/
/* Exercise5.cpp																*/
/* Author: Dr. Watts															*/
/* Modified by: Alana Reyna														*/
/* Date: 12/18/22 																*/
/* Description:	This program implements the recursive four-way flood fill 		*/
/*				algorithm.														*/
/********************************************************************************/

#include <iostream>
#include <fstream>
#include "Bitmap_Image.hpp"

using namespace std;

void Fill (bitmap_image & bmp, int currentX, int currentY, int red, int green, int blue);
void isInShape (bitmap_image & bmp, int x, int y, int fillRed, int fillGreen, int fillBlue);
void inShape (bitmap_image & bmp, int x, int y, int fillRed, int fillGreen, int fillBlue);
int x_inshape;
int y_inshape;
int width;
int height;
bool inShapeOrnah = false; 

int main (int argc, char * argv [])
{
	if (argc < 2)
	{
		cout << "Usage: " << argv [0] << " <filename>\n";
		exit (1);
	}
	string input, output;
	int x, y, red, green, blue;
	ifstream data (argv[1]);
	if (data.fail())
	{
		cout << "File " << argv[1] << " not found\n";
		exit (2);
	}
	data >> input >> output;
	data >> x >> y;
	data >> red >> green >> blue;
	bitmap_image image (input);

	width = image.width();
	height = image.height();

	// check if the point inputted is in the shape by calling isInShape function
	isInShape(image, x, y, red, green, blue);

	if (image.failed ())
	{
		cout << "File " << input << " could not be opened\n";
		exit (3);
	}
	if (inShapeOrnah == true)
	{
		Fill (image, x, y, red, green, blue);
	}
	else 
	{
		inShape (image, x, y, red, green, blue);
		Fill (image, x_inshape, y_inshape, red, green, blue);
		cout << "x: " << x_inshape << " y: " << y_inshape << endl;
	}
	image.save_image (output);
	return 0;
}

/********************************************************************************/
/* Function: isInShape														    */
/* Parameters: bitmap_image, x, y, red, green, blue								*/
/* Returns: None																*/
/* Description:	This program checks if the point is in the shape by getting     */
/*				pixels to the right of the point and counting the number of     */
/*				times pixels crossed the shape. If they cross an odd number of  */
/*				times, then it is within the shape and sets the global 			*/
/*				bool true.  													*/
/********************************************************************************/
void isInShape (bitmap_image & bmp, int x, int y, int fillRed, int fillGreen, int fillBlue)
{
	unsigned char r, b, g;
	bmp.get_pixel(x, y, r, b, g);
	int counter = 0;
	for (int i = x; i <= width; i++)
	{
		if (r == fillRed && b == fillGreen && g == fillBlue)
		{
			counter++;
		}
		bmp.get_pixel(i, y, r, b, g);
	}
	if (counter % 2 != 0 && counter != 0)
	{
		inShapeOrnah = true;
	}
	return;
}

/********************************************************************************/
/* Function: inShape														    */
/* Parameters: bitmap_image, x, y, red, green, blue								*/
/* Returns: None																*/
/* Description:	This program will find a point within the shape and set the     */
/*				global variables to the points. 								*/
/********************************************************************************/
void inShape (bitmap_image & bmp, int x, int y, int fillRed, int fillGreen, int fillBlue)
{
	unsigned char r, g, b;
	bmp.get_pixel(x, y, r, g, b);

	for (int i = 0; i <= height; i++)
	{

		for (int j = 0; j <= width; j++)
		{

			if (r == fillRed && g == fillGreen && b == fillBlue)
			{
				isInShape(bmp, j, i + 1, fillRed, fillGreen, fillBlue);
				if (inShapeOrnah == true)
				{
					x_inshape = j;
					y_inshape = i + 1;
				}
				return;
			}
			bmp.get_pixel(j, i, r, g, b);
		}
	}
	cout << "u fucked " << endl;
	return;
}

void Fill (bitmap_image & bmp, int currentX, int currentY, int fillRed, int fillGreen, int fillBlue)
{
	unsigned char r, b, g;
	bmp.get_pixel(currentX, currentY, r, b, g);

	if (currentX < 0 || currentX > bmp.width())
	{
		return;
	}
	else if (currentY < 0 || currentY > bmp.height())
	{
		return;
	}
	if (r == fillRed && b == fillGreen && g == fillBlue)
	{
		return;
	}
	bmp.set_pixel(currentX, currentY, fillRed, fillGreen, fillBlue);
	Fill (bmp, currentX - 1, currentY, fillRed, fillGreen, fillBlue);
	Fill (bmp, currentX, currentY - 1, fillRed, fillGreen, fillBlue);
	Fill (bmp, currentX + 1, currentY, fillRed, fillGreen, fillBlue);
	Fill (bmp, currentX, currentY + 1, fillRed, fillGreen, fillBlue);
}
