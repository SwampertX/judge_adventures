import java.util.*;

public class zamka{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int l,d,x,m,n;
        l = sc.nextInt();
        d = sc.nextInt();
        x = sc.nextInt();
        m = -1; n = 1000001;
        for(int i=l; i<=d; i++){
            String s = Integer.toString(i);
            int sum = 0;
            for(int j=0; j<s.length(); j++){
                sum += (s.charAt(j) - '0');
            }
            if(sum==x){
                n = Integer.min(n, i);
                m = Integer.max(m, i);
            }
        }System.out.printf("%d\n%d",n,m);
    }
}
