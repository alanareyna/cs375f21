// File: Exercise8b.java
// Author: Dr. Watts
// Modified by: Alana Reyna
// Contents: This file contains the implementation of a small
// GUI application.
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class reynaE8 extends JPanel implements ActionListener, MouseMotionListener, MouseListener 
{
    private boolean inScreen = true;
    private JButton theButton;
    private int hwX, hwY;
    private String helloWorld = null;
    private int red, green, blue;
    public reynaE8 ()
    {
        hwX = 300;
        hwY = 300;
        helloWorld = "Hello World";
        red = green = blue = 30;
        theButton = new JButton ("Change Color");
        add (theButton);
        theButton.addActionListener (this);
        addMouseMotionListener (this);
        addMouseListener (this);
        repaint();
    }
    public void mouseDragged(MouseEvent e)
    {
        if (inScreen == true)
        {
            hwX = e.getX();
            hwY = e.getY();
            repaint();
        }
        
    }
    public void mouseMoved(MouseEvent e) {}
    public void paintComponent (Graphics g)
    {
        super.paintComponent (g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
        RenderingHints.VALUE_ANTIALIAS_ON);
        g2.setPaint (new Color (red, green, blue));
        g2.setFont (new Font ("Arial", Font.PLAIN, 22));
        g2.drawString (helloWorld, hwX, hwY);
    }
    public void actionPerformed (ActionEvent e)
    {
        if (e.getSource() == theButton)
        {
            red = (red * 29) % 254 + 2;
            green = (green * 31) % 254 + 2;
            blue = (blue * 53) % 254 + 2;
            repaint ();
        }
    }

    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) 
    {
        inScreen = true;
    }
    public void mouseExited(MouseEvent e) 
    {
        inScreen = false;
    }
    public void mouseClicked(MouseEvent e) {}

    public static void main (String[] args)
    {
        JFrame frame = new JFrame ("reynaE8");
        reynaE8 reynaE8 = new reynaE8 ();
        frame.getContentPane().add (reynaE8);
        frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
        frame.setSize (600,600);
        frame.setVisible (true);
        frame.setResizable (false);
        frame.setLocation (200, 200);
    }
}