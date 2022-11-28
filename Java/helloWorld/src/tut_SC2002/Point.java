package tut_SC2002;

public class Point {
	protected int x;
	protected int y;
	
	//constructors with default constructor
	public Point() {
		x=0;
		y=0;
	}
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public String toString(){
		return "[" + x + "," + y + "]";
	}
	
	public void setPoint(int xx, int yy) {
		x = xx;
		y = yy;
	}
	
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
	
}
