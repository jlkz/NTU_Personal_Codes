package helloWorld;
import java.util.Scanner;
import java.io.*;

public class IOTest {

	public static void main(String[] args){
		try {
			Scanner scStream = new Scanner( new File( "C:\\Users\\jeric\\OneDrive\\Desktop\\names.txt" ) );
//			Scanner scStreamS = new Scanner( new File( "small.txt" ) );
//			Scanner scStreamL = new Scanner( new File( "large.txt" ) );
			FileWriter fwStreamS = new FileWriter( "C:\\Users\\jeric\\OneDrive\\Desktop\\small.txt" );
			FileWriter fwStreamL = new FileWriter( "C:\\Users\\jeric\\OneDrive\\Desktop\\large.txt" );
			String inputLine;
			while ( scStream.hasNext() )
			{
			inputLine = scStream.nextLine();
			System.out.println( inputLine );
			if(inputLine.length() > 5 ) {
				fwStreamL.write(inputLine + "\n");
			}
			else {
				fwStreamS.write(inputLine + "\n");
			}	
			}
			scStream.close();
			fwStreamS.close();
			fwStreamL.close();
		}
		catch(FileNotFoundException e){
			System.out.println( "File Error!" + e.getMessage() );
			System.exit( 0 );
		}
		catch(IOException e) {
			System.out.println( "IO Error!" + e.getMessage() );
			//e.printStackTrace();
			System.exit( 0 );
		}
	}

}
