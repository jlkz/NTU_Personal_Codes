package helloWorld;

public final class FiveGPhone extends mobilePhone implements InterPhone {
	
	private double dataRate;
	private double credit;
	
	public FiveGPhone(String owner, double price, double size, double dataRate, double credit ) {
		super(owner, price, size);
		//super.price = price;
		this.dataRate = dataRate;
		this.credit = credit;
	}
	
	public void ring() {
		System.out.print("Music play");
	}
	
	public final void  ring(String name ) {
		System.out.print(name + "is calling");
	}
	public void print() {
		super.print();
		System.out.print("Overrided superclass stuff");
	}
	
}
