import java.util.*;

public class autori{
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
        String s = sc.nextLine();
        String[] ss = s.split("-");
        StringBuilder out = new StringBuilder();
        for(String i: ss){
            out.append(i.charAt(0));
        }
        System.out.println((new String(out)).toUpperCase());
    }
}

