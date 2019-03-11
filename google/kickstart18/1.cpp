#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

ull n, p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        cin>>n>>p;
        ull ans = pow(2, n);
        while(p--){
            string temp; cin>>temp;
            ans -= pow(2, n - temp.length());
            cout<<ans<<'\n';
        } cout<<ans<<'\n';
    }
    return 0;
}
