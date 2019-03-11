#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main(){
    ull n,m;cin>>n>>m;
    ull ann[5]={n/5}, emm[5]={m/5};
    for(int i=1; i<5; i++){
        ann[i]=(n+5-i)/5;
        emm[i]=(m+5-i)/5;
    }
    ull no=0;
    no+=ann[0]*emm[0];
    for(int i=1; i<5; i++){
        no+=ann[i]*emm[5-i];
    }
    cout<<no<<endl;
}
