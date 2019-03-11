#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n;

int phi(int n){
    int result=n;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            result-= result/i;
        }
    } if (n>1) result -= result/n;
    return result;
}

int main(){
    while(cin>>n){
        if(n==0) return 0;
        cout<<phi(n)<<'\n';
    }
    return 0;
}
