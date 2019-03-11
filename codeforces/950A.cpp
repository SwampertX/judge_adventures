#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,r,a; cin>>l>>r>>a;
    int bl=l, br=r;
    if(l==r) cout<<l+r+(a-a%2);
    else{//make l the larger one
        l=max(bl,br); r=min(bl,br);
        if(l-r>a) cout<<(r+a)*2;
        else if(l-r==a) cout<<r*2;
        else cout<<l*2+(a-l+r)-(a-l+r)%2;
    }
}
