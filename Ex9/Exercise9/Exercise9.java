// File: Exercise9.java 
// Originally written by: Dr. Watts
// Modified by:
// Contents:
 
import java.awt.*; 
import java.awt.event.*;
import javax.swing.*;
 
public class Exercise9
{
	public static void main (String[] args) 
	{ 
		Data data;
		if (args.length > 0)
			data = new Data (args[0]);
		else
			data = new Data ();
		JFrame frame = new JFrame ("Exercise 9"); 
		Canvas canvas = new Canvas (data); 
		frame.getContentPane().add (canvas); 
		frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE); 
		frame.setSize (600,600); 
		frame.setVisible (true); 
		frame.setResizable (false); 
		frame.setLocation (200, 200); 
	} 
} 
