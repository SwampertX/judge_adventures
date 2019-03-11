import java.util.*;

public class throwns{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int acc = 0;
        Stack<Integer> s = new Stack<>();
        for(int i=0; i<k; i++){
            String temp = sc.next();
            if(temp.equals("undo")){
                int tt = sc.nextInt();
                for(int j=0; j<tt; j++){
                    acc += (-s.pop()%n + n) %n;
                }
            } else{
                s.push(Integer.parseInt(temp));
                acc += (s.peek()%n + n) %n;
            }
        }System.out.println(acc%n);
    }
}
