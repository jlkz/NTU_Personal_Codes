package lab_SC2002;

public class Square implements Shape {
	protected double length;
	
	public Square(double length) {
		this.length = length;
	}
	public double area() {
		return length *length;
	}
	
}
