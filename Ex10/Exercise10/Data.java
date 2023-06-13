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

		//for (int i = 0; i < elements.size(); i++)
		//	System.out.println (elements.get(i));
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
		return null;
	}

	public boolean moveSelectedBack ()
	{
		return false;
	}

	public boolean moveSelectedForward ()
	{
		return false;
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

// Add your DesignElement creation functions below this line
}
