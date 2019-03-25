#include <bits/stdc++.h>

using namespace std;

int r,c,cnt;
char grid[100][100];
int visited[100][100];

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int i, int j){
    if(i>=r || i<0 || j>=c || j<0 || visited[i][j]) return;
    if(grid[i][j]!='H') return;
    else {
        visited[i][j] = true;
        for(int k=0; i<4; k++){
            dfs(i+dir[k][0], j+dir[k][1]);
            cout<<i<<j<<'\n';
        }
    }
}

int main() {
    cin>>r>>c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            cin>>grid[i][j];
        }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!visited[i][j]){
                if(grid[i][j]=='H'){
                    cnt++;
                    dfs(i,j);
                } else visited[i][j] = true;
            }
        }
    }
    printf("Oh, bother. There are %d pools of hunny.\n", cnt);
}

