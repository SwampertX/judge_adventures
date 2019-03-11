import java.util.*;

public class sortofsorting{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        boolean first = true;
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            else{
                if(first) first=false;
                else System.out.println();
                String[] s = new String[n];
                for(int i=0; i<n; i++){
                    s[i] = sc.next();
                } Arrays.sort(s,
                        (s1, s2) ->
                            s1.substring(0,2).compareTo(s2.substring(0,2)));
                for(String i: s)System.out.println(i);
            }
        }
        
    }
}
