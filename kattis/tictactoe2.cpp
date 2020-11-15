#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    while(n--) {
        string rows[3];
        for(int i=0;i<3;i++) {
            cin>> rows[i];
        }
        scanf("\n");

        int nx=0, no=0, win=0;
        char winner;
        for(int i=0;i<3;i++){
            if(rows[i] == "XXX" || rows[i] == "OOO") {
                win++; winner = rows[i][0];
            }
            if(rows[0][i] == rows[1][i] && rows[1][i] == rows[2][i]) {
                if(rows[0][i] == 'X' || rows[0][i] == 'O') {
                    win++; winner = rows[0][i];
                }
            }
            for(int j=0;j<3;j++){
                if(rows[i][j] == 'X') { nx++; }
                else if (rows[i][j]=='O'){ no++; }
            }
        }


        if(rows[1][1] == rows[2][2] && rows[2][2] == rows[0][0]) {
            if(rows[1][1] == 'X' || rows[1][1] == 'O') {
                win++; winner = rows[1][1];
            }
        }

        if(rows[1][1] == rows[2][0] && rows[2][0] == rows[0][2]) {
            if(rows[1][1] == 'X' || rows[1][1] == 'O') {
                win++; winner = rows[1][1];
            }
        }

        /* printf("win %d nx %d no %d\n", win, nx, no); */
        if(win < 2 && nx - no >= 0 && nx -no <= 1 ) {
            /* printf("win %d nx %d no %d\n", win, nx, no); */
            if(win == 1 && winner=='X' && nx > no) cout<<"yes"<<"\n";
            else if(win == 1 && winner=='O' && nx == no) cout<<"yes"<<"\n";
            else cout<<"no"<<"\n";
        } else cout<<"no"<<"\n";

    }

    return 0;
}
