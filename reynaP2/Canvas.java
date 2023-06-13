// File: Canvas.java 
// Originally written by: Dr. Watts
// Modified by: Alana Reyna 
// Contents:
 
import java.awt.*; 
import java.awt.event.*;
import javax.swing.*;
 
public class Canvas extends JPanel implements ActionListener, MouseMotionListener, MouseListener, KeyListener
{
	JButton theButton;
	private Data data;
	private boolean inScreen = true;
	private int prevX = 0, prevY = 0;
	private DesignElement selectedElement = null;

	public Canvas (Data D) 
	{ 
		data = D;
		data.canvas = this;
		// theButton = new JButton("Save Design");
		// add (theButton);
		// theButton.addActionListener(this);
		addMouseMotionListener(this);
		addMouseListener(this);
		setFocusable (true);
		grabFocus();
		addKeyListener(this);
		repaint(); 
   	} 

	public void paintComponent (Graphics g) 
	{ 
		super.paintComponent (g); 
		Graphics2D g2 = (Graphics2D) g; 
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, 
		RenderingHints.VALUE_ANTIALIAS_ON); 
		for (int i = 0; i < data.elements.size(); i++)
			data.elements.get(i).paintElement (g2);
		grabFocus();
	} 

	public void mouseDragged(MouseEvent e)
	{
		//System.out.println ("Mouse dragged called" + e);
		if (selectedElement == null)
			return;
		int currentX = e.getX();
		int currentY = e.getY();
		if (e.isShiftDown())
		{ 
			// Resize selected element
			selectedElement.scale (prevX, prevY, currentX, currentY);
		}
		else if (e.isControlDown())
		{ 
			// Rotate selected element
			selectedElement.rotate (prevX, prevY, currentX, currentY);
		}
		else
		{ 
			// Move selected element
			selectedElement.translate (prevX, prevY, currentX, currentY);
		}
		prevX = currentX;
		prevY = currentY;
		repaint();
	}

	public void mouseMoved(MouseEvent e)
	{
		System.out.println ("Mouse moved called");
	}

	public void mousePressed(MouseEvent e)
	{
		System.out.println ("Mouse pressed called");
		selectedElement = null;
		for (int i = data.elements.size() - 1; i >= 0 && selectedElement == null; i--)
		{
			if (data.elements.get(i).inElement (e.getX(), e.getY()))
			{
				selectedElement = data.elements.get(i);
			}
		}
		prevX = e.getX();
		prevY = e.getY();
	}

	public void mouseReleased(MouseEvent e)
	{
		System.out.println ("Mouse released called");
	}

	public void mouseEntered(MouseEvent e) 
	{
		// System.out.println ("Mouse entered called");
		inScreen = true;
	}
	public void mouseExited(MouseEvent  e) 
	{
		// System.out.println ("Mouse exited called");
		inScreen = false;
	}
	public void mouseClicked(MouseEvent e)
	{
		System.out.println ("Mouse clicked called");
		selectedElement = null;
		for (int i = data.elements.size() - 1; i >= 0 && selectedElement == null; i--)
		{
			if (data.elements.get(i).inElement (e.getX(), e.getY()))
				selectedElement = data.elements.get(i);
		}
	}

	public void actionPerformed (ActionEvent e)
	{
		System.out.println ("Button pushed");
		if (e.getSource() == theButton)
		{
			FileIO fileio = new FileIO (data);
			fileio.writeFile ("reynaP2.txt");
		}
	}
 
	public void keyTyped (KeyEvent e)
	{
		System.out.println ("Key Listener event: " + e);
	}

	public void keyPressed (KeyEvent e)
	{
			System.out.println ("Key Listener event: " + e);
		if (selectedElement == null)
			return;
		if (e.getKeyCode () == KeyEvent.VK_KP_RIGHT || e.getKeyCode () == KeyEvent.VK_RIGHT) 
			selectedElement.translate (1, 0);
		else if (e.getKeyCode () == KeyEvent.VK_KP_LEFT || e.getKeyCode () == KeyEvent.VK_LEFT) 
			selectedElement.translate (-1, 0);
		else if (e.getKeyCode () == KeyEvent.VK_KP_DOWN || e.getKeyCode () == KeyEvent.VK_DOWN) 
			selectedElement.translate (0, 1);
		else if (e.getKeyCode () == KeyEvent.VK_KP_UP || e.getKeyCode () == KeyEvent.VK_UP) 
			selectedElement.translate (0, -1);
		else if (e.getKeyCode () == KeyEvent.VK_L) // responds to clicking L
			selectedElement.rotate (-2);
		else if (e.getKeyCode () == KeyEvent.VK_R) // responds to clicking R 
			selectedElement.rotate (2);
		else if (e.getKeyCode () == KeyEvent.VK_NUMPAD0 + 107 || 
				e.getKeyCode () == KeyEvent.VK_NUMPAD1 + 107 || 
				e.getKeyCode () == KeyEvent.VK_NUMPAD2 + 107 || 
				e.getKeyCode () == KeyEvent.VK_NUMPAD3 + 107 || 
				e.getKeyCode () == KeyEvent.VK_NUMPAD4 + 107 || 
				e.getKeyCode () == KeyEvent.VK_NUMPAD5 + 107 || 
				e.getKeyCode () == KeyEvent.VK_NUMPAD6 + 107 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD7 + 107 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD8 + 107 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD9 + 107 )
		{
			selectedElement.scale(0.05, 0.05);
		}
		else if (e.getKeyCode () == KeyEvent.VK_NUMPAD0 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD1 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD2 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD3 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD4 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD5 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD6 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD7 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD8 - 109 ||
				e.getKeyCode () == KeyEvent.VK_NUMPAD9 - 109)
		{
			selectedElement.scale(-0.05, -0.05);
		}
		else if (e.getKeyCode () == KeyEvent.VK_DELETE)
			data.deleteSelected();
		else if (e.getKeyCode () == KeyEvent.VK_B)
			data.moveSelectedBackward();
		else if (e.getKeyCode () == KeyEvent.VK_F)
			data.moveSelectedForward();
		repaint ();
	}

	public void keyReleased (KeyEvent e)
	{
			System.out.println ("Key Listener event: " + e);
	}
} 
