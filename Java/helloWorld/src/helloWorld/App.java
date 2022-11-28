package helloWorld;

public class App {
	private String name;
	private double cost;
	
	public App(String name, double cost) {
		this.name = name;
		this.cost = cost;
	}
	
	public void print() {
		System.out.print("The name of the app is: " + name + " and the cost is: " + cost);
	}
}
