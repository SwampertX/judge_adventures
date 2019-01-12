#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

ll k,n,a[5001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        a[i]+=a[i-1];
    } ll m(0);
    for(int i=0; i<n-k; i++){
        m=max(m, a[i+k]-a[i]);
    } long double ans;
    ans = double(m)/double(k);
    cout<<setprecision(10)<<fixed<<ans;
    return 0;
}
