package lab_SC2002;

import java.util.Scanner;

public class Shape3DApp {
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
				case "cuboid":
					System.out.println("Length: ");
					dimension = sc.nextDouble();
					System.out.println("Breadth: ");
					dimension2 = sc.nextDouble();
					Cuboid r = new Cuboid(dimension, dimension2);
					list[i] = r;
					break;
				case "sphere":
					System.out.println("Radius: ");
					dimension = sc.nextDouble();
					Sphere c = new Sphere(dimension);
					list[i] = c;
					break;
				case "pyramid":
					System.out.println("height: ");
					dimension = sc.nextDouble();
					System.out.println("Base: ");
					dimension2 = sc.nextDouble();
					Pyramid t = new Pyramid(dimension, dimension2);
					list[i] = t;
					break;
				case "cone":
					System.out.println("Radius: ");
					dimension = sc.nextDouble();
					System.out.println("height: ");
					dimension2 = sc.nextDouble();
					Cone k = new Cone(dimension, dimension2);
					list[i] = k;
					break;
				case "cylinder":
					System.out.println("Radius: ");
					dimension = sc.nextDouble();
					System.out.println("height: ");
					dimension2 = sc.nextDouble();
					Cylinder y = new Cylinder(dimension, dimension2);
					list[i] = y;
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
