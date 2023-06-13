#include <iostream>
using namespace std;

class Ex1
{
	public:
		Ex1 ()
		{
			intvalue = 0;
			doublevalue = 0;
		}
		Ex1 (int I, double D) {
			intvalue = I;
			doublevalue = D;
		}
		friend ostream & operator << (ostream & outs, const Ex1 & e)
		{
			outs << "Integer: " << e.intvalue;
			outs << "; Double: " << e.doublevalue;
			return outs;
		}
		int intvalue;
		double doublevalue;
};

int main ()
{
	Ex1 obj1;
	cout << "obj1 = " << obj1 << endl;
	Ex1 obj2 (5, 7.7);
	cout << "obj2 = " << obj2 << endl;
	obj1 = obj2;
	obj1.intvalue *= 2;
	cout << "obj1 = " << obj1 << endl;
	cout << "obj2 = " << obj2 << endl;
	return 0;
}
