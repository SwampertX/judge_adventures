import java.util.*;

public class classy{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Pair[] names = new Pair[100];
        int[] constant = new int[10];
        constant[0] = 59049;
        for(int i=1; i<10; i++){
           constant[i] = constant[i-1]/3; 
        }
        for(int i=0; i<t; i++){// each test case
            int n = sc.nextInt(); 
            for(int j=0; j<n; j++){// each name
                String name = sc.next();
                name = name.substring(0,name.length()-1);

                String c = sc.next();
                int[] cls = Arrays.stream(c.split("-"))
                    .mapToInt((x)-> x.equals("upper")
                            ? 2
                            : x.equals("middle")
                            ? 1
                            : 0)
                        .toArray();
                // for(int k: cls) System.out.println(k);
                int score = 0;
                for(int k=0; k<10; k++){
                    if(k<cls.length) score += cls[cls.length-1-k] * constant[k]; 
                    else score += constant[k];
                }
                names[j] = new Pair(score, name);
                sc.next(); // ignore the word class
            }
            Arrays.sort(names, 0, n);
            for(int j=0; j<n; j++) System.out.println(names[j].second);
            // for(int j=0; j<n; j++) System.out.printf("%s %d\n", names[j].second, names[j].first);
            for(int j=0; j<30; j++) System.out.print("=");
            System.out.println();
        }
    }
}
class Pair implements Comparable<Pair>{
    public int first;
    public String second;
    public Pair(int f, String s){
        first = f; second = s;
    }
    public int compareTo(Pair other){
        if(this.first == other.first){
            return this.second.compareTo(other.second);
        }else if (this.first > other.first) return -1;
        else return 1;
    }
}
