package lab_SC2002;

public class Pyramid implements Shape {
	private Triangle t;
	
	public Pyramid(double h, double b) {
		t = new Triangle(h,b);
	}
	public double area() {
		return 4*t.area() + t.base * t.base;
	}
	public double volume() {
		return t.base * t.base * t.height /3;
	}
}
