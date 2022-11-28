package lab_SC2002;

public class Cone implements Shape {
	private Circle c;
	private double height;
	public Cone(double r, double h) {
		c = new Circle(r);
		height = h;
	}
	
	public double area() {
		return c.area()+(2*3.14*c.radius* height);
	}
}
