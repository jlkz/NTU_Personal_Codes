package lab_SC2002;

public class Circle implements Shape{
	protected double radius;
	
	public Circle(double r) {
		radius = r;
	}
	public double area() {
		return 3.14*radius*radius;
	}

}
