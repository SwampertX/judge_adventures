#include <bits/stdc++.h>

using namespace std;

int t,r,c;
int dist[250][250];
int max_dist=-1;
pair<int,int> max_coor;

int dir[8][2] = {
    {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}
};

void dfs(int i, int j, int d) {
    if(i<r && i>=0 && j<c && j>=0) {
        max_dist = max(max_dist, d);
        if(max_dist == d) max_coor = make_pair(i,j);
        dist[i][j] = dist[i][j] == -1
            ? d : min(d, dist[i][j]);
        for(int k=0; k<8; k++){
            dfs(i+dir[k][0], j+dir[k][1], d+1);
        } 
    } 
}

int main() {
    cin>>t;
    for(int k=0; k<t; k++){
        cin>>r>>c;
        max_dist = -1;
        set<pair<int,int>> post;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                char temp;
                cin>>temp;
                dist[i][j] = temp=='0'? -1 : 0;
                if(dist[i][j] == 0) post.insert(make_pair(i,j));
            }

            for(auto temp: post)
                dfs(temp.first, temp.second, 0);
            
            post.insert(max_coor); 
            
            max_dist = -1;
            for(auto temp: post)
                dfs(temp.first, temp.second, 0);

            printf("Case #%d: %d\n", k+1, max_dist); 
    }
}
