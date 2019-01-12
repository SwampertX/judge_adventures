#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull n,m,k;

int main(){
    cin>>n>>m>>k;
    if(k<=n-1) cout<<k+1<<' '<<1;
    else{
        k-=n;
        if((k/(m-1)) % 2 ==0){//even, l to r
            cout<<n-k/(m-1)<<' '<<(k)%(m-1)+2;
        } else cout<<n-k/(m-1)<<' '<<m-k%(m-1);
    }
    return 0;
}

