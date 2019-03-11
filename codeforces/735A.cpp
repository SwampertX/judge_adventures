#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k; while(cin>>n>>k){
        string s; cin>>s;
        int g,t; bool can=true;
        g=s.find('G'); t=s.find('T');
        if(g<t){
            for(int i=g; i<t; i+=k){
                if(s[i]=='#'){can=false; break;}
            }
        } else{
            for(int i=g; i>t; i-=k){
                if(s[i]=='#'){can=false; break;}
            }
        }
        if(abs(t-g)%k!=0) cout<<"NO";
        else if(can) cout<<"YES";
        else cout<<"NO";
    }
}
