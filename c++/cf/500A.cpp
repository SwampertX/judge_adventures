#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
vector<int> adj[30005];
bool visited[30005];
void dfs(int s){
    if(visited[s]) return;
    visited[s]=true;
    for(auto u: adj[s]){
        dfs(u);
    }
}

int main(){
    int n,t;
    cin>>n>>t;
    for(int i=1; i<n; i++){
        int temp; cin>>temp;
        adj[i].push_back(temp+i);
    }
    dfs(1);
    cout<<(visited[t]?"YES":"NO");
}
