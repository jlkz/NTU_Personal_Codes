package tut_SC2002;
import java.util.Scanner;

public class CalculatorEX {
	private double result;
	public CalculatorEX() {
		result = 0.0;
	}
	public double resultValue() {
		return result;
	}
	
	public void doCalculation() throws UnknownOperatorException{
		Scanner sc = new Scanner(System.in);
		double in, newResult;
		char op = 'f';
			while(op != 'Q' || op != 'q'){
				op = sc.next().charAt(0);
				sc.nextLine();
				in = sc.nextDouble();
				if((op != '+') && (op != '-') && (op != '/') && (op != '*')){
					System.out.print(op);
					throw new UnknownOperatorException(op);
				}
				newResult = evaluate(op, result, in);
				System.out.println("result" + op + in +"="+newResult);
				result = newResult;
				System.out.println("updated result = " + result);
			}
		
	}
	
	public double evaluate(char op, double n1, double n2) {
		
		switch(op) {
			case '+':
				return n1 + n2;
			case '-':
				return n1 - n2;
			case '*':
				return n1*n2;
			case '/':
				return n1/n2;	
		}
		return 0;
	}
	
	public void handleUnknownOpException(UnknownOperatorException e) {	
		System.out.println(e.getMessage());
		System.out.println("Please reenter: ");
	}
	public static void main(String[] args) {
		CalculatorEX cal = new CalculatorEX();
		// creating an instance here so you dont have to use static methods
		System.out.println("Calculator is on \nresult = " + cal.resultValue());
			try {
				cal.doCalculation();
			}
			catch(UnknownOperatorException e) {
				cal.handleUnknownOpException(e);
				try {
					cal.doCalculation();
				}
				catch(UnknownOperatorException e1) {
					cal.handleUnknownOpException(e1);
				}
				catch(Exception e2) {
					System.out.println("Other Exception" + e2.getMessage());
				}
				finally {
					System.out.println("Exit");
					System.exit(0);
				}
			}
			catch(Exception e1) {
				System.out.println("Other Exception" + e1.getMessage());
			}
			
			System.out.println("Final result = " + cal.resultValue() + "/nEnd of Program");
		
	}

}
