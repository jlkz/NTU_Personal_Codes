package lab_SC2002;
import java.util.Scanner;

public class Shape2DApp {

	public static void main(String[] args) {
		int num, i;
		double dimension, dimension2, area = 0;
		String choice;
		Scanner sc = new Scanner(System.in);
		System.out.println("Total num of shapes: ");
		num = sc.nextInt();
		Shape[] list = new Shape[num];
		for(i=0; i<num; i++) {
			System.out.println("Choose shape: ");
			choice = sc.next();
			switch (choice) {
				case "square":
					System.out.println("Length: ");
					dimension = sc.nextDouble();
					Square s = new Square(dimension);
					list[i] = s;
					break;
				case "rectangle":
					System.out.println("Length: ");
					dimension = sc.nextDouble();
					System.out.println("Breadth: ");
					dimension2 = sc.nextDouble();
					Rectangle r = new Rectangle(dimension, dimension2);
					list[i] = r;
					break;
				case "circle":
					System.out.println("Radius: ");
					dimension = sc.nextDouble();
					Circle c = new Circle(dimension);
					list[i] = c;
					break;
				case "triangle":
					System.out.println("height: ");
					dimension = sc.nextDouble();
					System.out.println("Base: ");
					dimension2 = sc.nextDouble();
					Triangle t = new Triangle(dimension, dimension2);
					list[i] = t;
					break;
			}
		}
		System.out.println("Type: ");
		choice = sc.next();
		if(choice.equals("area")) {
			for(i=0; i<num; i++) {
				area+=list[i].area();
			}
		}
		System.out.println("Total area: " + area);
	}

}
