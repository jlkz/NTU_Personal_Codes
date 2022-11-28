package lab_SC2002;

public class Triangle implements Shape {
	protected double height;
	protected double base;
	
	public Triangle(double h, double b) {
		height = h;
		base = b;
	}
	
	public double area() {
		return 0.5*height*base;
	}
}
