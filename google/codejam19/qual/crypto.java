import java.util.*;

public class crypto {
    int n;
    ArrayList<Integer> primes = new ArrayList<>();
    boolean[] isprime = new boolean[100001];

    void sieve() {
        for(int i=0; i<n; i++) isprime[i] = true;
        isprime[0] = false;
        isprime[1] = false;
        for(int i=2; i<=n && isprime[n]; i++) {
            primes.add(i);
            for(int k=2; k*i<=n; k++) {
                isprime[k] = false;
            }
        }
    }

    public static void main(String[] args) {
        new crypto().run(); 
    }   
    void run() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sieve();
        int t = sc.nextInt();
        for(int tt=0; tt<t; tt++) {
            int up = sc.nextInt();
            int l = sc.nextInt();
            int[] order = new int[l];
            for(int ll=0; ll<l; ll++) {
                int temp = sc.nextInt();
                order[ll] = temp;
            }
            int[] sorted = Arrays.copyOf(order, l);
            // from the smallest number check if any prime
            // smaller than its sqrt is a factor
            HashSet<Integer> primesUsed = new HashSet<>();
            HashMap<Integer, int[]> factors = new HashMap<>();
            for(int i: sorted) {
                int[] currf = new int[2];
                boolean found = false;
                if(!primesUsed.isEmpty()) {
                    for(int p: primesUsed) {
                        if(i%p==0) {
                            currf[0] = p;
                            currf[1] = i/p;
                            primesUsed.add(p);
                            primesUsed.add(currf[1]);
                            found = true; break;
                        }
                    }
                } 
                if(!found)
                    for(int p: primes) {
                        if(i%p==0) {
                            currf[0] = p;
                            currf[1] = i/p;
                            primesUsed.add(p);
                            primesUsed.add(currf[1]);
                            break;
                        }
                    }
                factors.put(i,currf);
            }
            // store the identified primes in a set
            // after identifying all numbers' prime factors
            ArrayList<Integer> letters = 
                new ArrayList<Integer>(primesUsed);
            Collections.sort(letters);
            HashMap<Integer, Character> numtolet = new HashMap<>();
            for(int i=0; i< letters.size(); i++) {
                numtolet.put(letters.get(i), (char)('A'+i)); 
            }
            // print out the letters
            System.out.printf("Case #%d: ", tt+1);
            for(int num: order) {
                System.out.print(numtolet.get(num)); 
            } 
        }
    }
}
