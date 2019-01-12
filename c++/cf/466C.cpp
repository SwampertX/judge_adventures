#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n;
ll a[500000];

int main(){
    cin>>n>>a[0];
    for(int i=1; i<n; i++){cin>>a[i]; a[i]+=a[i-1];}
    ull b(0), c(0);
    for(int i=0; i<n-1; i++){
        if(a[i]*3==a[n-1]*2) c+=b;
        if(a[i]*3==a[n-1]) b++;
    }
    cout<<c<<endl;
    return 0;
}
