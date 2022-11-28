package lab_SC2002;

public class SalePerson implements Comparable {
	private String firstName;
	private String lastName;
	private int totalSales;
	
	public SalePerson(String f, String l, int t) {
		firstName = f;
		lastName = l;
		totalSales = t;
		
	}
	public String toString() {
		return lastName + " , " + firstName + " : "+ totalSales;
	}
	
	public boolean equals(Object o) {
		return ((((SalePerson)o).getFirstName() == firstName) && (((SalePerson)o).getLastName() == lastName));
	}
	
	public int compareTo(Object o) {
		if(this.totalSales < ((SalePerson)o).getTotalSales()){
			return -1;
		}
		
		if(this.totalSales == ((SalePerson)o).getTotalSales()) {
			if(lastName.compareTo(((SalePerson)o).getLastName()) > 0) {
				return -1;
			}
		}
		return 1;
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public int getTotalSales() {
		return totalSales;
	}
}
