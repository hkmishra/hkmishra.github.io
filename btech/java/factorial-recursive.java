// factorial recurssive program Main.java
import java.util.Scanner;

public class Main
{
    
    static int factorial(int n){
	    if(n==0) return 1;
	    return (n*(factorial(n-1)));
	}
    
	public static void main(String[] args) {
	    Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a = factorial(n);
		System.out.println("factorial = "+ a);
	}
	
	
}
