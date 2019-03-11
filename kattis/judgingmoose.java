import java.util.*;

public class judgingmoose{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int l = sc.nextInt();
		int r = sc.nextInt();


		if (l == r && r == 0){
			System.out.println("Not a moose");
		} else if(l == r) {
			System.out.println("Even " + 2*l);
		} else {
			System.out.println("Odd " + 2*Math.max(l,r));
		}
	}
}
