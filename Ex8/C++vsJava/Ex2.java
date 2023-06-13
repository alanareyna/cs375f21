class Ex2
{
	private int size;
	private double [] doublevalues;
	public Ex2 ()
	{
		size = 0;
		doublevalues = null;
	}
	public Ex2 (int S, double D)
	{
		size = S;
		doublevalues = new double [size];
		size = S;
		if (size == 0)
			doublevalues = null;
		else
		{
			doublevalues = new double [size];
			doublevalues[0] = D;
			for (int i = 1; i < size; i++)
				doublevalues[i] = doublevalues[i-1] * 1.1;
		}
	}
	public String toString ()
	{
		String string = "Size: " + size;
		string += "; Doubles:";
		for (int i = 0; i < size; i++)
			string += " " + doublevalues[i];
		return string;
	}
	public void copy (Ex2 other)
	{
		size = other.size;
		// doublevalues = new double [size];
		double newdoublesvalues[];
		newdoublesvalues = new double [size];
		for (int i = 0; i < size; i++)
			newdoublesvalues[i] = other.doublevalues[i];
	}
	public static void main (String args [])
	{
		Ex2 obj1 = new Ex2 ();
		System.out.println ("obj1 = " + obj1);
		Ex2 obj2 = new Ex2 (5, 7.7);
		System.out.println ("obj2 = " + obj2);
		obj1.copy (obj2);
		for (int i = 0; i < obj1.size; i++)
			obj1.doublevalues[i] *= 2;
		System.out.println ("obj1 = " + obj1);
		System.out.println ("obj2 = " + obj2);
	}
}
