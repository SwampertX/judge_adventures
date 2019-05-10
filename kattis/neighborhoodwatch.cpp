#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

ull k, n;

ull choosetwo(ull n){
    ull ans;
    ans = (n % 2 == 0? (n>>1)*(n-1) : (n-1)>>1 * n);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    cout<<choosetwo(k)+n*k<<endl; 
    return 0;
}
