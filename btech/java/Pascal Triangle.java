//Main.java
import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner in = new Scanner(System.in);
	    System.out.println("Enter no of rows: ");
	    int n = in.nextInt();
	    int m=(n*2)+2;
	    int arr[][]= new int[n][m];
	    
	    int i=0,j=0;
	    
	    for(i=0;i<m;i++){
	        arr[0][i]=0;
	        if(i==(m/2)-1) arr[0][i]=1;
	    }
	    
	    
	    for(i=1;i<n;i++){
	        //iterate through each row
	        for(j=0;j<m;j++){
                if(j>=1 && j<=m-2){ 
                    arr[i][j]=arr[i-1][j-1]+arr[i-1][j+1];
                }
	        }
	    }
	    
	    
	    System.out.println("\nPascal's Triangle: \n");
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
                if(arr[i][j]==0){System.out.print("   ");}
                else{
                    if(arr[i][j]<10)System.out.print(arr[i][j]+"   ");
                    else if(arr[i][j]<100)System.out.print(arr[i][j]+"  ");
                    else if(arr[i][j]<1000)System.out.print(arr[i][j]+" ");
                }
	        }
	        System.out.println("");
	    }
	    
	    

	}//end of main
}//end of class
