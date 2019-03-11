#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n,m;
ull a[200005], b[200005], c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){
        b[i]=b[i-1]+a[i];
    }

    while(m--){
        cin>>c; auto iter=lower_bound(b,b+n,c);
        int ind=iter-b;
        ull roomcapa = b[ind]-b[ind-1];
        cout<<ind<<' '<<roomcapa-(b[ind]-c)<<'\n';
    }
    return 0;
}
