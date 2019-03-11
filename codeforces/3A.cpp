#include <bits/stdc++.h>
using namespace std;

string b,c, a[8];
int rl, ud;

int main(){
    cin>>b>>c;
    rl=int(c[0]-b[0]);
    ud=int(c[1]-b[1]);
    for(int i=0; i<abs(rl); i++){
        a[i]+=(rl>0? 'R':'L');
    } for (int i=0; i<abs(ud); i++){
        a[i]+=(ud>0? 'U':'D');
    }
    cout<<max(abs(rl),abs(ud))<<endl;
    for(int i=0; i<max(abs(rl),abs(ud)); i++){
        cout<<a[i]<<endl;
    }
}
