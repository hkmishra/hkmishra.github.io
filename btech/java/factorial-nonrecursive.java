//facorial program Main.java
import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
	    Scanner in= new Scanner(System.in);
	    int n = in.nextInt();
	    int a=1;
	    while(n>1){
	        a *= n;
	        n--;
	    }
		System.out.println("facorial = "+a);
	}
}
