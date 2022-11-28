package helloWorld;

public class mergesort {
	public static void main(String args[]) {
		int arr[] = {12, 11, 13, 5, 5, 7, 6, 31, 65, 343, 1, 34, 42, 242, 3, 21, 77, 2, 63, 23, 20};
		printArr(arr);
		//mergesort dog = new mergesort();
		ms(arr, 0, 20);
		System.out.print("Sorted Array: ");
		printArr(arr);
	}
	
	private static void printArr(int arr[]) {
		int length = arr.length;
		for(int i=0; i<length; i++)
		{
			System.out.print(arr[i] + ", ");
		}
		System.out.println();
	}
	
	private static void ms(int arr[], int s, int e) {
		if(e-s<=0) 
			return;
		// size greater than 2 then break into 2, or else merge will do it
		else if (e-s > 1) {
			int mid = (s+e)/2;
			ms(arr, s, mid);	
			ms(arr, mid+1, e);
		}
		merge(arr, s, e);
	}
	
	private static void merge(int arr[], int s, int e) {
		if(e-s<=0)
			return;
		int mid = (s+e)/2;
		int temp, a=s, b=mid+1, i;
		while(a<=mid && b<=e) {
			//first is smaller
			if(arr[a]< arr[b]) {
				a++;
			}
			//second is smaller
			else if(arr[a]>arr[b]) {
				temp = arr[b];
				for(i=b; i>a; i--) {
					arr[i] = arr[i-1];
				}
				arr[a++]=temp;
				b++;
				mid++;
			}
			//same value
			else if(arr[a]==arr[b]) {
				if(a+1 == b)
					break;
				else {
					temp = arr[b];
					a++;
					for(i=b; i>a; i--) {
						arr[i]=arr[i-1];
					}
					arr[a++]=temp;
					b++;
					mid++;
				}
			}
			
		}	
	}
	

}
