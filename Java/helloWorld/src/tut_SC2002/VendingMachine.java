package tut_SC2002;
import java.util.Scanner;
import java.text.*;

public class VendingMachine {
	Scanner sc = new Scanner(System.in);
	DecimalFormat numForm = new DecimalFormat("0.00");
	// constructor
	public VendingMachine() {
		
	}
	// get the drink selection, and return the cost of the drink
	public double selectDrink() {
		System.out.println("Please enter selection:");
		int sel = sc.nextInt();
		return sel;
	}
	// insert the coins and returns the amount inserted
	public double insertCoins(double drinkCost) {
		double price = 0, amount=0.0;
		System.out.println("Please insert coins:\r\n"
				+ "========== Coins Input =========== \r\n"
				+ "|Enter 'Q' for ten cents input |\r\n"
				+ "|Enter 'T' for twenty cents input|\r\n"
				+ "|Enter 'F' for fifty cents input |\r\n"
				+ "|Enter 'N' for a dollar input |\r\n"
				+ "==================================");
		do{
			char coin = sc.next().charAt(0);
			if(coin == 'Q') {
				price = 0.10;
			}
			else if(coin == 'T') {
				price = 0.20;
			}
			else if(coin == 'F') {
				price = 0.50;
			}
			else if(coin == 'N') {
				price = 1.00;
			}
			amount += price;
			
			
			System.out.println("Coins inserted: " + numForm.format(amount));
		}while(amount<drinkCost);
		return amount;
		
	}
	// check the change and print the change on screen
	public void checkChange(double amount, double drinkCost) {
		System.out.println("Change: $ " + numForm.format(amount - drinkCost));
	}
	// print the receipt and collect the drink
	public void printReceipt(){
		System.out.print("Please collect your drink \n"
				+ "Thank you!!");
	}
}
