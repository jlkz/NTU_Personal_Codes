package lab_SC2002;
import java.util.Scanner;

public class P3 {
	
	public static void forLoop(int starting, int ending, int increment) {
		int i;
		System.out.println("US$           S$");
		System.out.println("-----------------");
		for(i=starting; i<=ending; i+=increment ) {
			System.out.println(i + "            " + i*1.82);
		}
		
	}
	public static void whileLoop(int starting, int ending, int increment) {
		int i = starting;
		System.out.println("US$           S$");
		System.out.println("-----------------");
		while(i<=ending){
			System.out.println(i + "            " + i*1.82);
			i+=increment;
		}
	}
	public static void doWhileLoop(int starting, int ending, int increment) {
		int i = starting;
		System.out.println("US$           S$");
		System.out.println("-----------------");
		do{
			System.out.println(i + "            " + i*1.82);
			i+=increment;
		}while(i<=ending);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Starting: ");
		int starting = sc.nextInt();
		System.out.print("Ending: ");
		int ending = sc.nextInt();
		System.out.print("Increment: ");
		int increment = sc.nextInt();
		if(starting > ending) {
			System.out.println("Error Input!!");
			return;
		}
		forLoop(starting, ending, increment);
		whileLoop(starting, ending, increment);
		doWhileLoop(starting, ending, increment);
	}

}
