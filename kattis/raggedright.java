import java.util.*;

public class raggedright{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int sum = 0; int[] arr = new int[100];
        int cnt = 0; int max = -1;
        while(sc.hasNext()){
            int temp = sc.nextLine().length();
            arr[cnt++] = temp;
            max = Integer.max(max, temp);
        }
        for(int i=0; i<cnt-1; i++){
            sum += (max - arr[i])*(max - arr[i]);
        } System.out.println(sum);
    }
}
