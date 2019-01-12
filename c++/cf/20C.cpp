#include <bits/stdc++.h>
#define INF 2e18

using namespace std;
typedef long long ll;

int n,m, p[100001];
vector<pair<int,int> > adj[100001];
priority_queue<pair<ll,int> > q;
ll dist[100001];

void trace(int n){
    if(p[n]!=-1) trace(p[n]);
    cout<<n<<' ';
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w}),adj[b].push_back({a,w});
    }
    fill(dist, dist+n+1, INF);
    fill(p,p+n+1, -1);
    dist[1]=0;
    q.push({0,1});
    while (!q.empty()){
        int a=q.top().second; q.pop();
        for (auto u: adj[a]){
            int b=u.first, w=u.second;
            if(dist[a]+w < dist[b]) {
                p[b]=a;
                dist[b]=dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
    if(dist[n]==INF) {cout<<-1; return 0;}
    trace(p[n]);
    cout<<n;
    return 0;
}
