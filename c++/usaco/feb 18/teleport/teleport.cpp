#include <bits/stdc++.h>
using namespace std;

void submit(){
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
}

int main(){
    submit();
    int a,b,x,y; cin>>a>>b>>x>>y;
    cout<<min( abs(b-a), min( abs(x-a)+abs(y-b), abs(y-a)+abs(x-b)));
}
