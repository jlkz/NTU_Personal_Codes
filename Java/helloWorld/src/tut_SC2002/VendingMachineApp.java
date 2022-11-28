package tut_SC2002;
import java.util.Scanner;

public class VendingMachineApp {
	private static VendingMachine vm = new VendingMachine();
	
	public static void main(String[] args) {
		double drinkCost = 0, sel, amount;
		System.out.println("====== Vending Machine ======\r\n"
				+ "|1. Buy Beer ($3.00) |\r\n"
				+ "|2. Buy Coke ($1.00) |\r\n"
				+ "|3. Buy Green Tea ($5.00) |\r\n"
				+ "|============================");
		
		sel = vm.selectDrink();
		if(sel == 1) {
			drinkCost = 3.0;
		}
		else if(sel==2) {
			drinkCost = 1.0;
		}
		else if(sel==3) {
			drinkCost = 5.00;
		}
		
		amount = vm.insertCoins(drinkCost);
		vm.checkChange(amount, drinkCost);
		vm.printReceipt();
		}
}
