import java.util.*;
public class guessthedatastructure{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int t = sc.nextInt();
            LinkedList<Integer> bag = new LinkedList<>();
            Queue<Integer> q = new LinkedList<>();
            Stack<Integer> s = new Stack<>();
            Queue<Integer> pq = new PriorityQueue<>();
            LinkedList<Integer> out = new LinkedList<>();

            boolean impos = false;
            for(int i=0; i<t; i++){
                int opr = sc.nextInt();
                int temp = sc.nextInt();
                if(opr == 1){
                    bag.add(temp);
                    s.add(temp);
                    q.add(temp);
                    pq.add(temp);
                } else if(opr == 2){
                    if(!bag.contains(temp)){
                        System.out.println("impossible");
                        impos = true;
                        break;
                    } else bag.remove(temp);
                    out.addFirst(temp);
                }
            }
            if(!impos) printAns(q,s,pq,out);
        }
    }

    private static void printAns(Queue<Integer> q, Stack<Integer> s, Queue<Integer> pq, LinkedList<Integer> out){
        boolean iss = true && !s.isEmpty();
        boolean isq = true && !q.isEmpty();
        boolean ispq = true && !pq.isEmpty();
        for(int i=0; i<out.size(); i++){
            int temp = out.pop();
            if(iss && temp != s.pop()){
                iss = false;
            }
            if(isq && temp != q.remove()){
                isq = false;
            }
            if(ispq && temp != pq.remove()){
                ispq = false;
            }
        }
        System.out.println(decide(iss, isq, ispq));
    }
    private static String decide(boolean iss, boolean isq, boolean ispq){
        if(!(iss || isq || ispq)) return "impossible";
        else if (iss && !isq && !ispq) return "stack";
        else if (!iss && isq && !ispq) return "queue";
        else if (!iss && !isq && ispq) return "priority queue";
        else return "not sure";
    }
}
