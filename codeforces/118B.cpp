#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n;

int main(){
    cin>>n;
    for(int i=0; i<2*n+1; i++){
        for(int j=0; j<2*n+1; i++){

            if(i-abs(n-j)>=0) cout<<i-abs(n-j);

        }
    }
    return 0;
}
