import java.util.*;

public class treasurehunt{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int r = sc.nextInt();
        int c = sc.nextInt();
        char[][] map = new char[r][c];

        for(int i=0; i<r; i++){
            map[i] = sc.next().toCharArray();
        }

        String res = hunt(map);
        System.out.println(res);
    }

    private static String hunt(char[][] map){
        int i = 0;
        int j = 0;
        int r = map.length;
        int c = map[0].length;

        boolean[][] visited = new boolean[r][c];
        int steps = 0;
        while(i<r && i>=0 && j<c && j>=0){
            if(map[i][j] == 'T' || visited[i][j]) break;
            visited[i][j] = true;
            steps++;
            if(map[i][j] == 'E') j++;
            else if (map[i][j] == 'N') i--;
            else if (map[i][j] == 'S') i++;
            else if (map[i][j] == 'W') j--;
        }
        if(i>=r || i<0 || j>=c || j<0) return "Out";
        else if(map[i][j] == 'T') return Integer.toString(steps);
        else return "Lost";
    }
}

/*
   public class land{
   private int i, j, r, c;
   private boolean[][] visited;
   private int[][] map;
   private int steps = 0;
   public void land(char[][] map_input){
   this.i = 0;
   this.j = 0;
   map = map_input;
   this.r = map.length;
   this.c = map[0].length;
   visited = new boolean[r][c];
   }

   public boolean is_inside(int i, int j){
   return (i < r && i>=0) && (j<c && j>=0);
   }

   public boolean found_treasure(int i, int j){
   return map[i][j] == "T";
   }

   public int move_row(char dir){
   if(dir=="N") return -1;
   else if (dir=="S") return 1;
   else return 0;
   }
   public int move_column(char dir){
   if(dir=="W") return -1;
   else if (dir=="E") return 1;
   else return 0;
   }

   public String walk(){
   while(is_inside(i, j) && !visited[i][j] && !found_treasure(i,j)){
   char direction = map[this.i][this.j];
   this.i += move_row(direction);
   this.j += move_column(direction);
   }
   if(!is_inside(i,j)) return "Out";
   else if(visited[i][j]) return "Lost";
   else return Integer.toString(this.steps);
   }
   }*/
