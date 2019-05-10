import java.util.*;

public class shortestpath1 {
    public static void main(String[] args) {
        new shortestpath1().run();
    }

    int[] dist;
    boolean[] visited;
    ArrayList<ArrayList<Pair>> adj;
    int n,m,q,s;
    Queue<Pair> pq;

    private void run() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        q = sc.nextInt();
        s = sc.nextInt();
        while(n+m+q+s != 0) {
            adj = new ArrayList<ArrayList<Pair>>();
            dist = new int[n];
            visited = new boolean[n];
            pq = new PriorityQueue<>();
            for(int i=0; i<n; i++) {
                dist[i] = (int) 2e9; 
                visited[i] = false;
                adj.add(new ArrayList<Pair>());
            }
            for(int i=0; i<m; i++) {
                adj.get(sc.nextInt()).add(new Pair(sc.nextInt(), sc.nextInt()));
                // edge, weight
            }
            dij(s);
            // bf(s);
            for(int i=0; i<q; i++) {
                int temp = sc.nextInt();
                System.out.println(dist[temp]>(int)3e7
                        ? "Impossible"
                        : dist[temp]);
            }
            n = sc.nextInt();
            m = sc.nextInt();
            q = sc.nextInt();
            s = sc.nextInt();
            if(n+m+q+s > 0)System.out.println();
        }
    }

    void dij(int s) {
        pq.add(new Pair(0,s));
        dist[s] = 0;
        while(!pq.isEmpty()) {
            int u = pq.poll().second;
            if(visited[u]) continue;
            visited[u] = true;
            for(Pair vw: adj.get(u)) {
                int v = vw.first;
                int w = vw.second;
                if(dist[v] >= dist[u]+w) {
                    dist[v] = dist[u]+w;
                    pq.add(new Pair(dist[v],v));
                }
            }
        }
    }

    void bf(int s) {
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n; j++) { // node
                for(Pair p: adj.get(j)) {
                    int u = j;
                    int v = p.first;
                    int w = p.second;
                    if(dist[v] < dist[u]+w) {
                        dist[v] = dist[u]+w;
                    }
                }
            }
        }
    }
}

class Pair implements Comparable<Pair>{
    public int first;
    public int second;
    public Pair(int f, int s) {
        first = f;
        second = s;
    }
    public int compareTo(Pair other) {
        return first == other.first
            ? second == other.second
            ? 0
            : second - other.second
            : first - other.first;
    }
}
