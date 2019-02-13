import java.util.*;

public class marswindow{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int jan = 1 + (n-2018)*12 - 4 + 26;
		int dec = jan + 11;
		jan %= 26; dec %=26;
		if (jan==0 || (jan>dec)) System.out.println("yes"); 
		else System.out.println("no");
	}
}
