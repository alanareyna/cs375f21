#include <iostream>
#include <cmath>
using namespace std; 

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  float rise = y2 - y1;
  float run = x2 - x1;
  float m = rise / run;
  float b = y1 - m * x1;

  if (x1 > x2) {
    for (int x = x1; x <= x2; x--){
      int y = m * x + b + 0.5;
      cout << x << ',' << y << endl;
    }
  }
  else if (x1 == x2) {
    if (y1 > y2) {
      for (int z = y1; z >= y2; z--){
	int y = z;
	cout << x1 << ',' << y << endl;
      }
    }
    else if (y1 < y2){
	for (int z = y1; z <= y2; z++){
	  int y = z;
	  cout << x1 << ',' << y << endl;
	}
      }
  }
  else if (abs(run) >= abs(rise)) {
    if (x1 < x2){
      for (int x = x1; x <= x2; x++){
	int y = m * x + b + 0.5;
	cout << x << ',' << y << endl;
      }
    }
    else {
      for (int x = x1; x >= x2; x--) {
	int y = m * x + b + 0.5;
	cout << x << ',' << y << endl;
      }
    }
  }
  else if (abs(rise) >= abs(run)){
    if (y1 < y2) {
      for (int y = y1; y <= y2; y++){
	int x = (y - b) / m + 0.5;
	cout << x << ',' << y << endl;
      }
    }
    else {
      for (int y = y1; y >= y2; y--) {
	int x = (y - b) / m + 0.5;
	cout << x << ',' << y << endl;
      }
    }
  }

  return 0;
  
  
}
