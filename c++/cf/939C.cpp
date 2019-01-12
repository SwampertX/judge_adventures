#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[10001], s, f;
    cin>>n; for(int i=0; i<n; i++){
        cin>>a[i+1];
    } cin>>s>>f;
    int b=f-s, sum, best(0), time;
    for(int i=1; i<=n; i++){
        sum=0;
        for(int j=0; j<b; j++){sum+=a[i+j];}
        if(sum>=best){time=n-i+1;}
    } cout<<time;
}
