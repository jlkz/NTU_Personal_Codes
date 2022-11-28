package lab_SC2002;
import java.util.Scanner;

public class PlaneApp {
	private static Plane p;
	
	public static void main(String[] args) {
		p = new Plane();
		int choice;
		System.out.print("(1) Show number of empty seats\r\n"
				+ "(2) Show the list of empty seats\r\n"
				+ "(3) Show the list of seat assignments by seat ID\r\n"
				+ "(4) Show the list of seat assignments by customer ID\r\n"
				+ "(5) Assign a customer to a seat\r\n"
				+ "(6) Remove a seat assignment\r\n"
				+ "(7) Exit\r\n"
				+ "Enter the number of your choice: ");
		Scanner sc = new Scanner(System.in);
		do {
			choice = sc.nextInt();
			switch(choice) {
				case 1:
					p.showNumEmptySeats();
					break;
				case 2:
					p.showEmptySeats();
					break;
				case 3:
					p.showAssignedSeats(true);
					break;
				case 4:
					p.showAssignedSeats(false);
					break;
				case 5:
					System.out.print("Assigning Seat.. \n\t Please enter SeatID: ");
					int seatID = sc.nextInt();
					System.out.print("Please enter Customer ID: ");
					int custID = sc.nextInt();
					p.assignSeat(seatID-1, custID);
					break;
				case 6:
					System.out.println("Enter SeatID to unassign customer from: ");
					seatID = sc.nextInt();
					p.unAssignSeat(seatID-1);
					break;
					
			}
		}while(choice != 7);
		

	}
}
