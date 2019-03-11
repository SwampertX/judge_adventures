import java.util.*;

public class lineup{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] org = new String[n];
        for(int i=0; i<n; i++){
            String temp = sc.next();
            org[i] = temp;
        }
        String[] sorted = org.clone();
        Arrays.sort(sorted);
        boolean asc = true;
        for(int i=0; i<n; i++){
            if(sorted[i] !=org[i]){
                asc = false; break;
            }
        }
        if(asc){
            System.out.println("INCREASING");
        } else{
            boolean dsc = true;
            for(int i=0; i<n; i++){
                if(sorted[i] !=org[n-1-i]){
                    dsc = false; break;
                }
            } if(dsc) System.out.println("DECREASING");
            else System.out.println("NEITHER");


        }
    }
}
