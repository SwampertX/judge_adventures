#include <bits/stdc++.h>
using namespace std;
#define INF 2e18

typedef unsigned long long ull;
typedef long long ll;

ll n,c,p;

int main(){
    cin>>n;
    p=n; c=1; ll i=2;
    while(i<n){
        if(n/i<p) {c++; p=n/i; i+=max(n%i,ll(1));}
        if(p==1) break;
    }
    cout<<c;
}
