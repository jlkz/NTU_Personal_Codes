package lab_SC2002;

public class Plane {
	PlaneSeat[] seat = new PlaneSeat[12];
	private int numEmptySeat;
	
	public Plane() {
		numEmptySeat = 12;
		for(int i=0; i<12; i++) {
			seat[i] =  new PlaneSeat(i);
		}
	}
	
	private PlaneSeat[] sortSeats() {
		PlaneSeat[] sortedSeat = new PlaneSeat[12];
		System.arraycopy(seat, 0, sortedSeat, 0, 12);
		PlaneSeat temp = new PlaneSeat();
 		for(int i = 1; i<12; i++) {
			for(int j = i; j>0; j--) {
				if(sortedSeat[j].getCustomerID() < sortedSeat[j-1].getCustomerID()) {
					temp = sortedSeat[j];
					sortedSeat[j] = sortedSeat[j-1];
					sortedSeat[j-1] = temp;
				}
			}
		}
 		return sortedSeat;
	}
	
	public void showNumEmptySeats() {
		System.out.println("There are " + numEmptySeat + " empty seats");
	}
	
	public void showEmptySeats() {
		System.out.println("The following seats are empty: ");
		for(int i = 0; i < seat.length; i++) {
			if(!(seat[i].isOccupied())) {
				System.out.println("SeatID " + (i+1));
			}
		}
	}
	
	public void showAssignedSeats(boolean bySeatID) {
		PlaneSeat[] temp = new PlaneSeat[12];
		System.out.println("The seat assignment is as follows:");
		if(bySeatID) {
			for(int i = 0; i < seat.length; i++) {
				if(seat[i].isOccupied()) {
					System.out.println("SeatID " + (seat[i].getSeatID()+1) + " assigned to CustomerID " + seat[i].getCustomerID());
				}
			}
		}
		
		else {
			temp = sortSeats();
			for(int i = 0; i < temp.length; i++) {
				if(temp[i].isOccupied()) {
					System.out.println("SeatID " + (temp[i].getSeatID()+1) + " assigned to CustomerID " + temp[i].getCustomerID());
				}
			}
		}
		
		
	}
	
	public void assignSeat(int seatID, int cust_id) {
		if(seat[seatID].isOccupied()) {
			System.out.println("Seat already assigned to a customer");
		}
		else {
			seat[seatID].assign(cust_id);
			System.out.print("Seat Assigned!");
			numEmptySeat--;
		}
	}
	
	public void unAssignSeat(int seatID) {
		if(seat[seatID].isOccupied()) {
			seat[seatID].unAssign();
			numEmptySeat++;
			System.out.println("Seat Unassigned!");
		}
	}

}
