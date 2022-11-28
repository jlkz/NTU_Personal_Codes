package lab_SC2002;
import java.util.Scanner;

public class P4 {

	public static void main(String[] args) {
			int i, j;
			Scanner sc = new Scanner(System.in);
			System.out.print("height = ");
			int height = sc.nextInt();
			if(height <= 0) {
				System.out.print("Error Input!!");
				return;
			}
			
			for(i=1; i<=height; i++) {
				for(j=1; j<=i; j++)
				{
					if(j%2 == 1 && i%2 == 1) {
						System.out.print("AA");
					}
					else if(j%2 == 0 && i%2 == 1) {
						System.out.print("BB");
					}
					else if(j%2 == 1 && i%2 == 0) {
						System.out.print("BB");
					}
					else if(j%2 == 0 && i%2 == 0) {
						System.out.print("AA");
					}
				}
				System.out.print("\n");
			}

	}

}
