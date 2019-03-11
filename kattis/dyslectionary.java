import java.util.*;

public class dyslectionary{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        ArrayList<String> words = new ArrayList<String>();
        String l; 
        while(sc.hasNext()){
            l = sc.nextLine();
            if(l.isEmpty()){// blank line, end of word group
                process(words);
                words.clear();
                System.out.println();
            }else{
                words.add(l);
            }
        }
        process(words);
    }

    private static void process(ArrayList<String> words){
        int maxlen = 0;
        for(int i=0; i<words.size(); i++){
            maxlen = Math.max(maxlen, words.get(i).length());
        }
        Collections.sort(words, new Comparator<String>() {
            @Override
            public int compare(String w1, String w2) {
                StringBuilder sb1 = new StringBuilder(w1);
                StringBuilder sb2 = new StringBuilder(w2);
                sb1.reverse(); sb2.reverse();
                w1 = new String(sb1); w2 = new String(sb2);
                return w1.compareTo(w2);
            }
        });

        printAns(maxlen, words);
    }

    private static void printAns(int maxlen, ArrayList<String> words){
        for(int i=0; i<words.size(); i++){
            String format = "%" + maxlen + "s\n";
            System.out.printf(format, words.get(i));
        }
    }
}

