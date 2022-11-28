package lab_SC2002;

public class PlaneSeat {
	private int seatID;
	private boolean assigned;
	private int customerID;
	
	//constructors
	public PlaneSeat() {
		seatID = 0;
		assigned = false;
		customerID = 0;
	}
	public PlaneSeat(int seat_id) {
		seatID = seat_id;
	}
	
	public int getSeatID() {
		return seatID;
	}
	
	public int getCustomerID() {
		return customerID;
	}
	public boolean isOccupied() {
		return assigned;
	}
	
	public void assign(int cust_id) {
		customerID = cust_id;
		assigned = true;
	}
	
	public void unAssign() {
		assigned = false;
		customerID = 0;
	}
	
}
