package tut_SC2002;

import tut_SC2002.Polygon.KindofPolygon;

public class Rectangle extends Polygon {
	public Rectangle(String theName, float theWidth, float theHeight)
	{
		super(theName, theWidth, theHeight);
		polytype = KindofPolygon.POLY_RECT;
	}
	
	public float calArea() { 
		return (float)width*height; 
	}
	

}
