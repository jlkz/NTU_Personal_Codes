package lab_SC2002;

public class Cuboid implements Shape{
	private Rectangle r;
	private Square s;
	
	public Cuboid (double l, double b) {
		r = new Rectangle(l,b);
		s = new Square(b);
	}
	
	public double area() {
		return 4*r.area() + 2*s.area(); 
	}
	
	public double volume() {
		return s.area()*r.length;
	}
}
