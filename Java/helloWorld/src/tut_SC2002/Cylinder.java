package tut_SC2002;

public class Cylinder extends Circle {
	public double height;
	
	public Cylinder(int x, int y, double radius, double height) {
		//super(x, y, radius);
		this.height = height;
	}
	
	public void setHeight(double height) {
		this.height = height;
	}
	
	public double getHeight() {
		return height;
	}
	
	public String toString() {
		/*return "[" + (x+radius) + "," + (y+radius) + "]" + "[" + (x-radius) + "," + (y-radius) + "]" +
			"[" + (x+radius+height) + "," + (y+radius+height) + "]" + "[" + (x-radius+height) + "," + (y-radius+height) + "]";*/
		return "";
	}
	
	public double area() {
		return ((2*PI*radius*radius) +  PI*2*radius*height);
	}
	
	public double volume() {
		double a = area();
		return (a*height);
	}
}
