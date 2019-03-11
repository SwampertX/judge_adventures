#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    string a="hello"; int x=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==a[x])x++;
        if(x==5) break;
    }
    cout<<(x==5?"YES":"NO")<<endl;
}
