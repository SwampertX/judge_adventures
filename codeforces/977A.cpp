#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n,k;

int main(){
    cin>>n>>k;
    while(k--){
        if(n%10==0){n/=10;}
        else n--;
    } cout<<n;
    return 0;
}
