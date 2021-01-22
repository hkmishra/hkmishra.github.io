//program to swap two no based on choice by using temp or without temp
//Main.java
import java.util.Scanner;
public class Main
{
    
	public static void main(String[] args) {
	    Scanner in = new Scanner(System.in);
	    System.out.print("Enter a: ");
	    int a = in.nextInt();
	    System.out.print("\nEnter b: ");
	    int b = in.nextInt();
	    System.out.print("\nEnter 1 for swap without temp and 2 for swap using temp variable :");
	    int choice = in.nextInt();
	    
	    if(choice == 1){
	        a = a+b;
	        b = a-b;
	        a = a-b;
	    }
	    else{
	        int temp;
	        temp = b;
	        b = a;
	        a = temp;
	    }
	    
	    System.out.println("a = "+a+" b = "+b);
		
	}
}
