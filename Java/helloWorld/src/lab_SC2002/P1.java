package lab_SC2002;
import java.util.Scanner;

public class P1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String choice = "";
		do {
			choice  = sc.nextLine();
			
			if(choice.equals("A") || choice.equals("a")) {
				System.out.println("Action movie fan");
			}
			else if(choice.equals("C") || choice.equals("c")) {
				System.out.println("Comedy movie fan");
			}
			else if(choice.equals("d") || choice.equals("D")) {
				System.out.println("Drama movie fan");
			}
			else {
				System.out.println("Invalid choice");
			}
		}
		while (!"1".equals(choice));

	}

}
