class Ex1
{
	private int intvalue;
	private double doublevalue;
	public Ex1 ()
	{
		intvalue = 0;
		doublevalue = 0;
	}
	public Ex1 (int I, double D)
	{
		intvalue = I;
		doublevalue = D;
	}
	public String toString ()
	{
		String string = "Integer: " + intvalue;
		string += "; Double: " + doublevalue;
		return string;
	}
	public void copy (Ex1 other)
	{
		intvalue = other.intvalue;
		doublevalue = other.doublevalue;
	}
	public static void main (String args [])
	{
		Ex1 obj1 = new Ex1();
		System.out.println ("obj1 = " + obj1);
		// Ex1 obj2 (5, 7.7);

		// added for Pt1 #4
		// Ex1 obj2 ();
 		// obj2.intvalue = 5;
 		// obj2.doublevalue = 7.7;

		// added for Pt1 #6
		Ex1 obj2 = new Ex1(5, 7.7);
		System.out.println ("obj2 = " + obj2);
		//obj1 = obj2;
		// replaced previous line with following:
		obj1.copy(obj2);
		obj1.intvalue *= 2;
		System.out.println ("obj1 = " + obj1);
		System.out.println ("obj2 = " + obj2);
	}
}