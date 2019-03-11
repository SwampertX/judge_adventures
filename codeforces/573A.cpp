#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int gcd(ull a, ull b){
    if(b>a) return gcd(b,a);
    else if(b==0) return a;
    else if (b==1) return 1;
    else return gcd(b, a%b);
}

int main(){
    int n; while(cin>>n){
        ull bets[100001];
        for(int i=0; i<n; i++){
            cin>>bets[i];
        } ull g=gcd(bets[0],bets[1]);
        for(int i=0; i<n; i++){
            if(bets[i]%2==0)
        }
    }
}
