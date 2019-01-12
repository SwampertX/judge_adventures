#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; while(cin>>s){
        int l=s.length();
        int i=0, four=3; while(i<l){
            if(s[i]=='1') {i++; four=0;}
            else if(s[i]=='4' and four<2) {four++; i++;}
            else break;
        }
        if(i==l) cout<<"YES";
        else cout<<"NO";
    }
}
