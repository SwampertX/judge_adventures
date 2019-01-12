#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll d1,d2,k;

int main(){
    cin>>d1>>d2>>k;
    ll big=max(d1,d2), small=min(d1,d2);
    if(big-small>k){
        small+=k;
        cout<<double(big*small/2.0);
    } else{
        ull now=(big+small+k)/2;
        cout.precision(17);
        cout<<double(now*(now+(big+small+k)%2)/2.0);
    }
    return 0;
}

