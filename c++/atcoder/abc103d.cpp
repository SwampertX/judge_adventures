#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

int n,m;
vector<ii> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    a.push_back({1,n});
    int t1,t2; bool flag=false;
    while(m--){
        cin>>t1>>t2; flag=false;
        for(int i=0; i<a.size(); i++){
            if(t1>=a[i].second || t2<=a[i].first) continue;
            else{
                flag=true;
                a[i].first=max(a[i].first, t1);
                a[i].second=min(a[i].second, t2);
                break;
            }
        } if(!flag){a.push_back({t1,t2});}
    }
    //for(ii b:a){cout<<b.first<<' '<<b.second<<'\n';}
    cout<<a.size();
    return 0;
}
