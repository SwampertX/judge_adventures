import java.util.*;

public class evenup {
    int n;
    List<Integer> l = new ArrayList<>();
    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new evenup().run();
    }

    public void run() {
        n = sc.nextInt();
        for(int i=0; i<n; i++) {
            l.add(sc.nextInt());
        }
        // group odd numbers up
        for(int i=0; i<l.size(); i++) {
            if(l.get(i)%2==0) {
                // closest to even number, check bf and aft
                if(i>=2 && i<l.size()-2) {
                    int temp = l.get(i-1) + l.get(i-2);
                    int temp2 = l.get(i+1) + l.get(i+2);
                    if(temp%2==0) {
                        l.remove(i-2);
                        i--;
                    }
                    if(temp2%2==0)
                        l.remove(i-1);
                    i--;
                } else if (i>=2) {
                    int temp = l.get(i-1) + l.get(i-2);
                    if(temp%2==0) {
                        l.remove(i-2);
                        i--;
                    }
                    i--;
                } else if (i<l.size()-2) {
                    int temp = l.get(i+1) + l.get(i+2);
                    if(temp%2==0) {
                        l.remove(i-2);
                        i--;
                    }
                    i--;
                }
            }
        }
        for(int i=0; i<l.size(); i++) {
            if(l.get(i)%2==0) {
                // closest to even number, check bf and aft
                if(i>=2 && i<l.size()-2) {
                    int temp = l.get(i-1) + l.get(i-2);
                    int temp2 = l.get(i+1) + l.get(i+2);
                    if(temp%2==0) {
                        l.remove(i-2);
                        i--;
                    }
                    if(temp2%2==0)
                        l.remove(i-1);
                    i--;
                } else if (i>=2) {
                    int temp = l.get(i-1) + l.get(i-2);
                    if(temp%2==0) {
                        l.remove(i-2);
                        i--;
                    }
                    i--;
                } else if (i<l.size()-2) {
                    int temp = l.get(i+1) + l.get(i+2);
                    if(temp%2==0) {
                        l.remove(i-2);
                        i--;
                    }
                    i--;
                }
            }
        }
    }
}
