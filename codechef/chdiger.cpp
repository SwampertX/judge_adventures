#include <bits/stdc++.h>

using namespace std;

int t; char d;

int main() {
    cin>>t;
    while(t--){
        string str; cin>>str>>d;
        string ans; string tail;
        for(char c: str){
            if(c < d) ans += c;
            else tail+=d;
        }
        cout<<ans+tail<<'\n';
    }
}
