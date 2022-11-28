package helloWorld;

import java.util.ArrayList;


public class mobilePhone {
	
	protected String name;
	protected double price;
	protected double screenSize;
	//private App app;
	//private ArrayList<App> appStore;
	
	//constructors must have same name as class
	public mobilePhone() {
		name = "g";
		price = 5;
		screenSize = 6;
	}
	public mobilePhone(String name, double price, double size) {
		this.name = name;
		this.price = price;
		screenSize = size;
	}
	
//	public mobilePhone(String name, double price, App app, ArrayList<App> appStore) {
//		this(name, price);
//		this.app = app;
//		this.appStore = appStore;
//		
//	}
	
	//Accessors	
	public String getname() {
		return name;
	}
	public double getprice() {
		return price;
	}
	public double getSize() {
		return screenSize;
	}
//	public App getApp() {
//		return app;
//	}
//	public ArrayList<App> getAppStore(){
//		return appStore;
//	}
	
	//Mutators
	public void setprice(double price) {
		this.price = price;
	}
	public void setname(String name) {
		this.name = name;
	}
	public void setSize(double screenSize) {
		if(screenSize> InterPhone.MAX_SCREEN_SIZE) {
			this.screenSize = InterPhone.MAX_SCREEN_SIZE;
		}
		else {
			this.screenSize = screenSize;
		}
	}
//	public void setAppStore(ArrayList<App> appStore) {
//		this.appStore = appStore;
//	}
//	public void setApp(App app) {
//		this.app = app;
//	}
	
	public String sendSMS(String receiver){
		return "receive";
	}
	
//	public void ring() {
//		System.out.print("Ring");
//	}
	public void print() {
		System.out.println("The name of the app is: " + name + " The price is: "+ price);
	}
}
