package tut_SC2002;
import java.util.Scanner;

public class CircleApp {
	public static Circle cock;
	
	public static void main(String[] args) {
		System.out.println("==== Circle Computation =====");
		System.out.println("|1. Create a new circle      |\r\n"
				+ "|2. Print Area                        |\r\n"
				+ "|3. Print circumference               |\r\n"
				+ "|4. Quit                              |\r\n"
				+ "=============================\r\n"
				+ "Choose option (1-3):");
		int choice = 4;
		do {
		//System.out.println("Choose choice");
		Scanner sc = new Scanner(System.in);
		choice = sc.nextInt();
		if(choice == 1) {
			
			double rad = sc.nextDouble();
			//cock = new Circle(rad);
			System.out.println("new circle created");
		}
		else if(choice == 2) {
			if(cock != null) { // ERROr checking
				System.out.println("Radius: " + cock.getRadius());
				cock.printArea();
			}
			
		}
		else if(choice == 3) {
			System.out.println("Radius: " + cock.getRadius());
			cock.printCircumference();
		}
	
		}while(choice != 4);
		System.out.println("Thank YOu");
	}
}
