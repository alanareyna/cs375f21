// File: Data.java
// Originally written by: Dr. Watts
// Modified by: Alana Reyna
// Contents:

import java.awt.*;
import java.util.*;
import javax.swing.*;
import java.awt.geom.GeneralPath;
import java.awt.image.*;

public class Data
{
	public Canvas canvas;
	public Image image;
	public Design6 design6;
	public Design8 design8;
	public Kaleidoscope kaleidoscope;
	public ArrayList<DesignElement> elements;
	public DesignElement selectedElement = null;
	public int selectedIndex = -1;
	public Color currentStroke = Color.BLACK;
	public Color currentFill = Color.WHITE;
	public DesignElement onDeckElement = newHeart (0, 0, 90, 90, Color.BLACK, Color.WHITE);
	public SelectedPanel selected;

	public Data ()
	{
		elements = new ArrayList<DesignElement> ();
		// Add your element instantiations here
		elements.add (newRectangle(400, 400, 200, 100, Color.BLACK, Color.MAGENTA));
		elements.add (newRectangle(300, 150, 100, 150, Color.BLACK, Color.MAGENTA));
		elements.add (newHeart(300, 150, 100, 150, Color.WHITE, Color.ORANGE));
		elements.add (newHeart(400, 400, 200, 100, Color.WHITE, new Color(143, 219, 163)));

		elements.add (newLeaf(200, 300, 100, 150, Color.GREEN, new Color(39, 112, 54)));
		elements.add (newTriangle(200, 450, 100, 150, Color.PINK, new Color(72, 3, 77)));

		for (int i = 0; i < elements.size(); i++)
			System.out.println (elements.get(i));
	}

	public Data (String fileName)
	{
		elements = new ArrayList<DesignElement> ();
		FileIO io = new FileIO (this);
		io.readFile (fileName);
	}

	public DesignElement getSelected (int mouseX, int mouseY)
	{
		if (selectedElement != null)
			selectedElement.isSelected = false;
		selectedElement = null;
		selectedIndex = -1;
		for (int i = elements.size() - 1; i >= 0 && selectedElement == null; i--)
			if (elements.get(i).inElement (mouseX, mouseY))
			{
				selectedElement = elements.get(i);
				selectedIndex = i;
			}
		if (selectedElement != null)
			selectedElement.isSelected = true;
		return selectedElement;
	}

	public DesignElement getNewElement (int mouseX, int mouseY)
	{
		DesignElement newOne = onDeckElement.clone ();
		newOne.moveTo (mouseX, mouseY);
		newOne.isSelected = true;
		elements.add (newOne);
		selectedElement = newOne;
		selectedIndex = elements.size() - 1;
		return newOne;
	}

	public DesignElement deleteSelected ()
	{
		selectedElement = null;
		selectedIndex = -1;
		return null;
	}

	public boolean moveSelectedBackward ()
	{
		if (selectedElement == elements.get(0))
			return false;
		elements.add(selectedElement);
		selectedIndex -= 1;
		return true;
	}

	public boolean moveSelectedForward ()
	{
		if (selectedElement == elements.get(0))
			return false;
		elements.add(selectedElement);
		selectedIndex += 1;
		return true;
	}

	public DesignElement newRectangle (double cx, double cy, double width, double height, Color stroke, Color fill)
	{
		DesignElement rect = new DesignElement ();
		rect.centerX = cx;
		rect.centerY = cy;
		rect.strokeColor = stroke;
		rect.fillColor = fill;
		rect.path.moveTo (cx-width/2, cy-height/2);
		rect.path.lineTo (cx+width/2, cy-height/2);
		rect.path.lineTo (cx+width/2, cy+height/2);
		rect.path.lineTo (cx-width/2, cy+height/2);
		rect.path.lineTo (cx-width/2, cy-height/2);
		return rect;
	}

	public DesignElement newHeart (double cx, double cy, double width, double height, Color stroke, Color fill)
	{
		DesignElement heart = new DesignElement ();
		heart.centerX = cx;
		heart.centerY = cy;
		heart.strokeColor = stroke;
		heart.fillColor = fill;
		heart.path.moveTo (cx, cy-height/3);
		heart.path.curveTo (cx-0.44*width, cy-0.87*height, cx-0.87*width, cy, cx, cy+height/2);
		heart.path.curveTo (cx+0.87*width, cy, cx+0.44*width, cy-0.87*height, cx, cy-height/3);
		return heart;
	}

	public DesignElement newLeaf (double cx, double cy, double width, double height, Color stroke, Color fill)
	{
		DesignElement leaf = new DesignElement ();
		leaf.centerX = cx;
		leaf.centerY = cy;
		leaf.strokeColor = stroke;
		leaf.fillColor = fill;
		leaf.path.moveTo (cx, cy - height/2);
		leaf.path.curveTo (cx, cy - height/2, cx-1.2*width, cy, cx, cy+height/2);
		leaf.path.curveTo (cx + width/2, cy - height/2, cx-width, cy, cx, cy-height/2);
		return leaf;
	}

	public DesignElement newTriangle (double cx, double cy, double width, double height, Color stroke, Color fill)
	{
		DesignElement triangle = new DesignElement ();
		triangle.centerX = cx;
		triangle.centerY = cy;
		triangle.strokeColor = stroke;
		triangle.fillColor = fill;
		triangle.path.moveTo (cx - width/2, cy - height/2);
		triangle.path.lineTo (cx + width/2, cy - height/2);
		triangle.path.lineTo (cx + width/3, cy);
		triangle.path.lineTo (cx - width/2, cy - height/2);
		return triangle;
	}

// Add your DesignElement creation functions below this line
}
