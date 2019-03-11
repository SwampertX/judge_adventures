#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

ll m,n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    if(n%2==0 || m%2==0){
        m<=2 && n<=2? cout<<0:cout<<m*n;
    }else cout<<m*n-1;
    return 0;
}

