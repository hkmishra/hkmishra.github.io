import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
		int n=22;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		if(n%2==0){
		    System.out.println("number is even");
		}else{
		    System.out.println("number is odd");
		}
	}
}
