package tut_SC2002;

public class TestPolygon {
	//static binding
	public static void printArea(Rectangle r) {
		System.out.println("Area is: " + r.calArea());
	}
	
	public static void printArea(Triangle t) {
		System.out.println("Area is: " + t.calArea());
	}
	
	//dynamic binding
	public static void printArea(Polygon poly) {
		System.out.println("Area is: " + poly.calArea());
	}
	public static void main(String[] args){
		Rectangle r = new Rectangle("Rectangle", 5, 10);
		Triangle t = new Triangle("Triangle", 5, 10);
		// static binding overloading
		printArea(t);
		printArea(r);

		
	}
}
