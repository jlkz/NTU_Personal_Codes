package lab_SC2002;

import java.util.Scanner;

public class Strings {
	public static void main(String[] args)
	{
		//int[] intList;
		Comparable[] intList;
		int size;
		String temp;
		Scanner scan = new Scanner(System.in);
		System.out.print ("\nHow many string do you want to sort? ");
		size = scan.nextInt();
		intList = new Comparable[size];
		//intList = new int[size];
		System.out.println ("\nEnter the String...");
		for (int i = 0; i < size; i++) {
			temp = scan.next();
			intList[i] = temp;
		}
			Sorting.insertionSort(intList);
			System.out.println ("\nYour numbers in sorted order...");
		for (int i = 0; i < size; i++)
			System.out.print(intList[i] + " ");
		System.out.println ();
	}
}
