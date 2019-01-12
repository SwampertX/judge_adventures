#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int n=s.length();
    int ab(0), ba(0), over(0);
    for(int i=0; i<n; i++){
        if(s.substr(i,2)=="AB"){
            if(s.substr(i,3)=="ABA") {over++; i+=2;}
            else {ab++; i++;}
        }
        else if (s.substr(i,2)=="BA"){
            if(s.substr(i,3)=="BAB") {over++; i+=2;}
            else {ba++; i++;}
        }
    }if(ab==0 && ba==0){cout<<(over>=2?"YES":"NO");}
    else cout<<(over+min(ab,ba)>0?"YES":"NO");

}
