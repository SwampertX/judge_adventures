#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;


int main(){
    int t; cin>>t;
    for(int x=0; x<t; x++){
        ull d, dam(0); string p; ull rec[31];
        cin>>d>>p;
        int l=p.length(), power(1);
        for(int i=0; i<l; i++){
            if(p[i]=='C') {power*=2; rec[i]=power;}
            else{dam+=power;}
        }
        if(dam<=d) {cout<<0<<endl; continue;}
        int sw(0);
        for(int i=l-2; i>=0; i--){
            if(p.substr(i,2)=="CS"){
                p[i]='S'; p[i+1]='C';
                sw++; dam-=(rec[i]/2);
                rec[i+1]=rec[i]; rec[i]=0;
                i+=2;
            }
            if(dam<=d)break;
        }
        cout<<"Case #"<<x+1<<": ";
        if(dam<=d) cout<<sw<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
}
