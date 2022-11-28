package helloWorld;

public class Knapsack {
	
	// max function
	public static int max(int j, int k) {
		return(((j>k) ? j: k));
	}
	
	
	//computed using bottom up
	public static int unboundedKnapsack(int[] weight, int[] price, int capacity, int n, int[] dp) {
		int[] item = new int[capacity+1];
		
		for(int i = 0 ; i<=capacity; i++) {
			System.out.print(i + ": [");
			for(int j = 0; j<n ; j++) {
				if(weight[j]<= i) {
					if((dp[i-weight[j]]+ price[j]) > dp[i]) {
						item[i] = j;
					}
					dp[i] = max(dp[i], dp[i-weight[j]]+ price[j]);
					System.out.print(" " + dp[i]);
					
				}
			}
			System.out.println(" ]");
		}
		
		int i = capacity;
		while(i>0 & i>weight[item[i]]){
			System.out.println( "Item taken: " + item[i]);
			i = i-weight[item[i]]; 	
		}
		return dp[capacity];
	}
	
	
	
	
	
	public static void main(String[] args) {
		int capacity = 14;
		int weight[] = {4, 6, 8};
		int price[] = {7, 6, 9};
//		int weight[] = {5, 6, 8};
//		int price[] = {7, 6, 9};
		int n = weight.length;
		//dp 1D array 
		int dp[] = new int[capacity+1];
		for(int i = 0; i<capacity; i++) {
			dp[i] = 0;
		}
		
		System.out.println("Maximum Profit: " + unboundedKnapsack(weight, price, capacity, n, dp));
	}
}
