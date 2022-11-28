package lab_SC2002;
import java.util.Scanner;

public class P2 {

	public static void main(String[] args) {
		char grade = ' ';
		Scanner sc = new Scanner(System.in);
		System.out.println("Salary: ");
		int salary = sc.nextInt();
		System.out.println("Merit: ");
		int merit = sc.nextInt();
		
		if (salary >= 700 && salary <= 899) {
			if(salary<799 && merit < 20)
			{
				grade = 'B';
			}
			else
			{
				grade = 'A';
			}
		}
		else if (salary>= 600 && salary <= 799) {
			if(salary<649 && merit < 10)
			{
				grade = 'C';
			}
			else
			{
				grade = 'B';
			}
		}
		else if(salary>= 500 && salary <= 649) {
			grade = 'C';
		}
		
		System.out.println("salary: $" + salary + ", merit: " + merit + " - Grade " + grade);
			
	}

}
