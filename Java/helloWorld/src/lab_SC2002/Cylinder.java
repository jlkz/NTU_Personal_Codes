package lab_SC2002;

public class Cylinder implements Shape{
	private Circle c;
	private double height;
	
	public Cylinder(double r, double h) {
		c =new Circle(r);
		height = h;
	}
	
	public double area() {
		return 2*c.area()+(2*c.radius*3.14*height);
	}
}
