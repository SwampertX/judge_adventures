import java.util.*;

public class numbertree {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        String cmd = sc.hasNext()?sc.next():"";
        int minus = 0;
        for(int i=0; i<cmd.length(); i++) {
            if(cmd.charAt(i)=='L') {
                minus = 2* (minus+1)-1;
            } else minus = 2*(minus+1);
        }
        System.out.println((1<<h+1)-minus-1);
    }
}
