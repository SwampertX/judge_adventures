import java.util.*;

public class bookingaroom{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        int[] arr = new int[r];
        if(n<=r) System.out.println("too late");
        else{
            Set<Integer> booked = new HashSet<>();
            for(int i=0; i<r; i++){
                booked.add(sc.nextInt());
            }
            for(int i=1; i<=n; i++){
                if(!booked.remove(i)){
                    System.out.println(i);
                    break;
                }
            }
        }
    }
}

