import java.util.*;

public class integerlists{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for(int i=0; i<t; i++){
            String bapc = sc.nextLine();
            int n = Integer.parseInt(sc.nextLine());
            StringBuilder raw = new StringBuilder(sc.nextLine());

            // keep left, right pointer
            int l=0, r=n-1;
            boolean head = true;
            boolean error = false;
            // move, if left>=right break and print
            for(int j=0; j<bapc.length(); j++){
                if(bapc.charAt(j) == 'R') head = !head;
                else if (head) l++;
                else r--;
                if (l>r){
                    error = true;
                    break;
                } 
            }
            if(error) System.out.println("error");
            else{
                if(l>r) System.out.println("[]");
                else if (head){
                    String[] arr = raw.substring(1,raw.length()-1).split(",");
                    System.out.print("[");
                    for(int j=l; j<=r; j++){
                        if(j==l) System.out.print(arr[j]);
                        else System.out.printf(",%s",arr[j]);
                    }
                    System.out.println("]");
                } else{
                    String[] arr = raw.substring(1,raw.length()-1).split(",");
                    System.out.print("[");
                    for(int j=r; j>=l; j--){
                        if(j==r) System.out.print(arr[j]);
                        else System.out.printf(",%s",arr[j]);
                    }
                    System.out.println("]");
                }
            }         
        }
    }
}
