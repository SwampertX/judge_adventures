#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m,a;
int main(){
    cin>>n>>m;
    while(n<m){
        m%2?m++:m/=2;
        a++;
    } cout<<n-m+a;
}
