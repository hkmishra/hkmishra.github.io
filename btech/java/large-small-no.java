//Main.java
//program to find largest no and smallest no from array
import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner in = new Scanner(System.in);
	    int a[];
	    System.out.println("Count of numbers: ");
	    int count  = in.nextInt();
	    a = new int[count];
	    int i;
	    System.out.println("Enter numbers: ");
	    for(i=0;i<count;i++){
	        a[i] = in.nextInt();
	    }
	    
	    int largest= a[0];
	    int smallest = a[0];
	    for(i=0;i<count;i++){
	        if(a[i]>largest)
	            largest = a[i];
	        else if(a[i]<smallest)
	            smallest = a[i];
	    }
	    
	    System.out.println("Largest no = "+largest);
	    System.out.println("smallest no = "+smallest);
	}
}
