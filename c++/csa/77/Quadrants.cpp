#include <bits/stdc++.h>
using namespace std;

int n,x,y;
bool q[4];
int main() {
    cin>>n;
    while(n--){
        cin>>x>>y;
        if(x>0 and y>0) q[1]=true;
        if(x>0 and y<0) q[0]=true;
        if(x<0 and y>0) q[2]=true;
        if(x<0 and y<0) q[3]=true;
    } int c=0;
    for(auto x: q){if(x)c++;}
    cout<<c;
}
