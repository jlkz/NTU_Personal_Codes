package tut_SC2002;

public class Circle {
	protected double radius; // radius of circle
	protected static final double PI = 3.14159;
	protected Point centre;
	// constructor
	public Circle() {
		this.centre = new Point(1, 1);
		radius = 1;
	}
	public Circle(double rad, int a, int b) {
		//super(x,y);
		this.centre = new Point(a, b);
		radius = rad;
	}
	// mutator method – set radius
	public void setRadius(double rad){
		radius = rad;
	}
	
	public String toString() {
		
		//return "[" + (x+radius) + "," + (y+radius) + "]" + "[" + (x-radius) + "," + (y-radius) + "] " + super.toString();
		//using back the superclass' class methods
		return "";
	}
	
	// accessor method – get radius
	public double getRadius(){
		return radius;
	}
	// calculate area
	public double area(){
		return PI * radius * radius;
		// or return Math.PI * Math.pow(radius,2);
	}
	// calculate circumference
	public double circumference() {
		return 2*PI*radius;
	}
	// print area
	public void printArea(){
		System.out.println("Area: " + PI * radius * radius);
	}
	// print circumference
	public void printCircumference(){
		System.out.println("Circumference: " + 2*PI*radius);
	}

}
