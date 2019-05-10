import java.io.*;
import java.util.*;

public class joinstrings {
    public static void main(String[] args) {
        new joinstrings().run();
    }

    private void run() {
        FastReader s = new FastReader();
        int n = s.nextInt();
        String[] words = new String[n+1];
        ArrayList<LinkedList<Integer>> l = new ArrayList<>();
        l.add(new LinkedList<Integer>());
        for(int i=1; i<=n; i++) {
            words[i] = s.next();
            l.add(new LinkedList<Integer>());
            l.get(i).addLast(i);
        }
        for(int i=0; i<n-1; i++) {
            int a, b; a = s.nextInt(); b =  s.nextInt();
            if(i==n-2) {
                for(int k: l.get(a)) System.out.print(words[k]);
                for(int k: l.get(b)) System.out.print(words[k]);
                break;
            }
            l.get(a).addAll(l.get(b));
        }
    }
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader( new InputStreamReader(System.in) );
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        String nextLint() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e){
                e.printStackTrace();
            } return str;
        }
    }
}


