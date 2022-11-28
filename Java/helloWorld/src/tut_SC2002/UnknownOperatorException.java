package tut_SC2002;

public class UnknownOperatorException extends Exception{

	public UnknownOperatorException() {
	}
	public UnknownOperatorException(char op) {
		super(op + " is an unknown operator");
	}
	public UnknownOperatorException(String message) {
		super(message);
	}
}
