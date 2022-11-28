package lab_SC2002;
import java.util.Scanner;
import java.util.Random;

public class Lab2p1 {
	public static void main(String[] args){
		int choice;
		Scanner sc = new Scanner(System.in);
		do {
			System.out.println("Perform the following methods:");
			System.out.println("1: miltiplication test");
			System.out.println("2: quotient using division by subtraction");
			System.out.println("3: remainder using division by subtraction");
			System.out.println("4: count the number of digits");
			System.out.println("5: position of a digit");
			System.out.println("6: extract all odd digits");
			System.out.println("7: quit");
			choice = sc.nextInt();
			
		switch (choice) {
			 case 1: 
				 mulTest();
				 break;
			 case 2:
				 System.out.print("m = ");
				 int m = sc.nextInt();
				 System.out.print("n = ");
				 int n = sc.nextInt();
				 System.out.println(m + "/" + n + " = "+ divide(m,n));
				 
				 break;
			 case 3: /* add modulus() call */
				 System.out.print("m = ");
				 m = sc.nextInt();
				 System.out.print("n = ");
				 n = sc.nextInt();
				 System.out.println(m + "%" + n + " = "+ modulus(m,n));
				 break;
			 case 4: /* add countDigits() call */
				 System.out.print("n : ");
				 n = sc.nextInt();
				 if(n<0) {
					 System.out.println(" -Error input!!");
				 }
				 else {
					 System.out.println(" -count = " + countDigits(n));
				 }
				 break;
			 case 5: /* add position() call */
				 System.out.print("n : ");
				 m = sc.nextInt();
				 System.out.print(",digit : ");
				 n = sc.nextInt();
				 System.out.println("position = " + position(m,n));
				 break;
			 case 6: /* add extractOddDigits() call */
				 System.out.print("n : ");
				 long nn = sc.nextInt();
				 if(nn<0) {
					 System.out.println(" oddDigits = Error input!!");
				 }
				 else{
					 System.out.println("oddDigits = " + extractOddDigits(nn));
				 }
				 
				 break; 
			 case 7: System.out.println("Program terminating …");
			}
		} while (choice < 7);
		 }
		 /* add method code here */
	public static void mulTest() {
		int i, j, k, result, correct = 0;
		for(i =0 ; i<5; i++) {
			Random rand = new Random();
			Scanner sc = new Scanner(System.in);
			j = rand.nextInt(10);
			k = rand.nextInt(10);
			result = j*k;
			
			System.out.print("How much is " + j + " times " + k + "?");
			if(result == sc.nextInt()) {
				correct++;
			}
			System.out.println("");
		}
		System.out.println("......... \n" + correct + " out of 5 are correct.\n");
	}
	public static int divide(int m, int n) {
		int i = 0;
		while(m>0) {
			m -= n;
			if(m<0) {
				break;
			}
			i++;
		}
		return i;
	}
	public static int modulus(int m, int n) {
		while(m>0) {
			m-=n;
			if(m<0) {
				m +=n;
				break;
			}
		}
		return m;
	}
	public static int countDigits(int n) {
		int num = 0;
		if(n==0) {
			return 1;
		}
		while(n>0) {
			n /= 10;
			num++;
		}
		return num;
	}
	public static int position(int n, int m) {
		int count = 0;
		while(n>0) {
			if(n%10 == m) {
				return count+1;
			}
			n /= 10;
			count++;
		}
		return -1;
	}
	public static long extractOddDigits(long n) {
		long result = 0,rresult =0, temp;
		//find odd digits
		while (n!=0) {
			temp = n%10;
			if(temp %2 == 1) {
				result = result * 10 + temp;
			}
			n/=10;
		}
		if(result == 0) {
			return -1;
		}
		//reverse result
		while (result!=0) {
			temp = result%10;
			result/=10;
			rresult = rresult*10 + temp;
		}
		return rresult;
		
	}
}
