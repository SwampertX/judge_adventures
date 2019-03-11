import java.util.*;

public class statistics{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int i=0; int n;
		while(sc.hasNext()){
			n = sc.nextInt();
			int mx = Integer.MIN_VALUE;
			int mn = Integer.MAX_VALUE;
			for(;n>0;n--){
				int temp = sc.nextInt();
				if(temp>mx) mx = temp;
				if(temp<mn) mn = temp;
			}
			System.out.printf("Case %d: %d %d %d\n", i+1, mn, mx, mx-mn);
			i++;
		}
	}
}
