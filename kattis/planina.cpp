#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull a[16];

int main(){
    a[0]=4;
    ull b; cin>>b;
    for(ull i=1; i<=b; i++){
        a[i]=a[i-1]+pow(2,i-1)*(3*pow(2,i-1)+2);
    } cout<<a[b];
    return 0;
}
