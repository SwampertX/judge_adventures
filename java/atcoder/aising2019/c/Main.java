// incomplete
import java.utils.*

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		String[] s = new String[401];
		for(int i=0; i<h; i++){
			s[i] = sc.nextLine;
		}


		// search all black tiles
		int ans = 0;
		for(int i=0; i<w; i++){
			for(int j=0; j<w; j++){
				if(s[i][j] == '#'){//black
					ans += search(i, j, s, h, w);	
				}
			}
		}
	}
	
	public static bool inside(int i, int j, int h, int w){
		return (i<h) && (j<w);
	}

	public static int search(int i, int j, String[] s, int h, int w){
		int[][] dir = {
			{0,1},
			{1,0},
			{0,-1},
			{-1,0},
		}
		boolean[][] visited = new boolean[h][w];
		visited[i][j] = true;

		for(int k=0; k<4; i++){
			int ii = i + dir[k][0];
			int jj = j + dir[k][0];
			if(inside(ii, jj, h, w)){
				if(s[ii][jj] == s[i][j]){
					// same color, reject
					continue;
				} else{
					if(visited[ii][jj]) continue;
					else {
						visited[ii][jj] = true;
						search(ii, jj, s, h, w);
					}
				}
			}
		}
	}

}
