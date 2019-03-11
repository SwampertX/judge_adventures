import java.util.*;

public class mia{
	public static void main(String[] args){
		int[] s = new int[2];
		int[] r = new int[2];
		Scanner sc = new Scanner(System.in);

		for(int i=0; i<2; i++){
			s[i] = sc.nextInt();
		}
		for(int i=0; i<2; i++){
			r[i] = sc.nextInt();
		}

		while(s[0] != 0){
			int winner = mia(s, r);
			if(winner != 0){
			System.out.println("Player " + winner + " wins.");
			} else System.out.println("Tie.");
			for(int i=0; i<2; i++){
				s[i] = sc.nextInt();
			}
			for(int i=0; i<2; i++){
				r[i] = sc.nextInt();
			}
		}
	}

	private static int mia(int[] s, int[] r){
		int sscore = Math.max(10*s[0] + s[1], 10*s[1] + s[0]);
		int rscore = Math.max(10*r[0] + r[1], 10*r[1] + r[0]);
		if (sscore == rscore) return 0;
		else if (sscore == 21) return 1;
		else if (rscore == 21) return 2;
		else if (rscore % 11 == 0 && sscore %11 == 0){
			if (sscore > rscore) return 1;
			else return 2;
		}
		else if (sscore % 11 == 0) return 1;
		else if (rscore % 11 == 0) return 2;
		else if (sscore > rscore) return 1;
		else return 2;
	}
}
