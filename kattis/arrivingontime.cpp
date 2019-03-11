#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

ll dist[100001];
vector<pair<ii, ii> > adj[100001];
priority_queue<pair<ll, int> > q;
int n,m,s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>s;
    for(int i=0; i<m; i++){
        int u,v,t,p,d; cin>>u>>v>>t>>p>>d;
        adj[v].push_back({{u,d},{t,p}});
    }
    for(int i=0; i<n; i++) dist[i]=-INF;
    dist[n-1]=s; q.push({s,n-1});
    //below is djikstra
    while(!q.empty()){
        int a=q.top().second; q.pop();
        for(pair<ii,ii> x: adj[a]){//travel from a to b
            int b=x.first.first, d=x.first.second;
            int t0=x.second.first, freq=x.second.second;
            //the t0 and freq caveat
            if(t0+d>dist[a]) continue;
            else d+=(dist[a]-d-t0)%freq;
            //done, push node
            if(dist[b]<dist[a]-d){
                dist[b]=dist[a]-d;
                q.push({dist[b], b});
            }
        }
    } //djikstra ends
    cout<<(dist[0]>=0?to_string(dist[0]):"impossible");
    return 0;
}
