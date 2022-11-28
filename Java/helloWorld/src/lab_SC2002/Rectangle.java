package lab_SC2002;

public class Rectangle extends Square {
	protected double breadth;
	
	public Rectangle(double length, double breadth) {
		super(length);
		this.breadth = breadth;
	}
	
	public double area() {
		return length*breadth;
	}
	
}
