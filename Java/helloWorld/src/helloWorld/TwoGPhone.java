package helloWorld;

public class TwoGPhone extends mobilePhone implements InterPhone {
	
	public TwoGPhone (String owner, double price, double screenSize) {
		super.name = owner;
		super.price = price;
		super.screenSize = screenSize;

	}
	
	public String sendSMS(String receiver) {
		System.out.println("this is a 2g phone");
		return super.sendSMS(receiver);
	}
	public void ring() {
		System.out.println("Ring 2g");
	}
}