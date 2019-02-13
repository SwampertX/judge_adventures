import java.util.*;

class princesspeach{
    static int n,y;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        y = sc.nextInt();
        Set<Integer> found = new HashSet<>();
        for(int i=0; i<y; i++){
            found.add(sc.nextInt());
        } 
        printans(found);
    }
    private static void printans(Set<Integer> found){
        int size = found.size();
        for(int i=0; i<n; i++){
            if(!found.remove(i)) System.out.println(i);
        }
        System.out.printf("Mario got %d of the dangerous obstacles.", size);
    }
}
