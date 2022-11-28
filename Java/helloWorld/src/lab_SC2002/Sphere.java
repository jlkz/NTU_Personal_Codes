package lab_SC2002;

public class Sphere implements Shape {
	private Circle c;
	
	public Sphere(double r) {
		this.c = new Circle(r);
	}
	
	public double area() {
		return 4*3.14*(c.radius)*(c.radius);
	}
	public double volume() {
		return 4/3*3.14*(c.radius)*(c.radius)*(c.radius);
	}
}
