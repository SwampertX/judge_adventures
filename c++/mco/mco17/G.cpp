#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

vector<pair<int, ull> > adj[200005];
pair<ull,ull> timing[200005];
ull dist[200005];
int n,m;
priority_queue<pair<ll, int> > q;
int s;

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        ull s,e;
        cin>>s>>e; timing[i]={s,e};
    } for(int i=0; i<m; i++){
        int u,v; ull w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin>>s;
    //done input

    fill(dist, dist+n+5, INF);
    dist[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int a=q.top().second; q.pop();
        //process node a
        for(auto u: adj[a]){
            int b=u.first; ull w=u.second;
            //settle time complications
            ull newdist=dist[a];
            int day=timing[a].first, night=timing[a].second;
            ull sleep=newdist%(day+night);
            if(sleep>=day) newdist+=(night+day-sleep);
            //time complication ends here
            if(newdist+w<dist[b]){
                dist[b]=newdist+w;
                q.push({-dist[b],b});
            }
        }
    }
    for(int i=1; i<=n; i++){cout<<dist[i]<<' ';}
    return 0;
}
