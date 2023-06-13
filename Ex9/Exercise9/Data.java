// File: Data.java
// Originally written by: Dr. Watts
// Modified by:
// Contents:

import java.awt.*;
import java.util.*;
import javax.swing.*;
import java.awt.geom.GeneralPath;

public class Data
{
	public ArrayList<DesignElement> elements;
	public Canvas canvas;

        public Data ()
        {
		elements = new ArrayList<DesignElement> ();
		elements.add (newRectangle(300, 300, 200, 100, Color.BLUE, Color.CYAN));
		elements.add (newRectangle(100, 200, 100, 150, Color.BLACK, Color.WHITE));
		elements.add (newHeart(100, 200, 100, 150, Color.RED, Color.PINK));
		elements.add (newHeart(300, 300, 200, 100, new Color(167,66,245), new Color(230,191,245)));
		for (int i = 0; i < elements.size(); i++)
			System.out.println (elements.get(i));
        }

        public Data (String fileName)
        {
		elements = new ArrayList<DesignElement> ();
		FileIO io = new FileIO (this);
		io.readFile (fileName);
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
}
