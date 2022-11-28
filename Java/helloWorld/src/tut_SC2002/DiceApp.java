package tut_SC2002;
import java.util.Random;
import java.util.Scanner;

public class DiceApp {
	
	private int valueOfDice;
	
	public DiceApp(){
		setDiceValue();
	}
	public void setDiceValue() {
		Random rand = new Random();
		// Obtain a number between [0 - 49].
		int n = rand.nextInt(6)+1;
		valueOfDice = n;
	}
	public int getDiceValue() {
		return valueOfDice;
	}
	public void printDiceValue(){
		System.out.println("Current Value is " + getDiceValue());
	}
	

	public static void main(String[] args) {
		System.out.println("Press <key> to roll the first dice");
		DiceApp da = new DiceApp();
		//da.setDiceValue();
		da.printDiceValue();
		System.out.println("Press <key> to roll the 2nd dice");
		DiceApp daa = new DiceApp();
		daa.setDiceValue();
		daa.printDiceValue();
		System.out.println("Your total number is: " + (da.getDiceValue()+daa.getDiceValue()));
			
	}

}
