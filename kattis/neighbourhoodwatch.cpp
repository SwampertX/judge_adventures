#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

ull k, n;

ull chooseplus(ull n){
    ull ans;
    ans = (n % 2 == 0? (n/2)*(n-1) : (n-1)/2 * n);
    ans += n;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    ull ans=chooseplus(n);

    ull temp; cin>>temp; k--;
    ull t2;
    while(k--){
         cin>> t2;
        ull diff = t2-temp-1;
        ans -= chooseplus(diff);
    } ull diff = n-t2;
     ans -= chooseplus(diff);
    cout<<ans;
    return 0;
}
