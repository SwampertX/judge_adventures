#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[5001]; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){
        if(i==a[a[a[i]]] and i!=a[a[i]]){cout<<"YES"; break;}
        else if (i==n) {cout<<"NO";}
    }
    return 0;
}
