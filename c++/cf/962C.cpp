#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

string s, cur;
set<int> sq;
int c=99999,n;

int main(){
    cin>>s;
    for(int i=1; i*i<=stoi(s); i++){
        sq.insert(i*i);
    }
    for(int i=0; i<(1<<s.length()); i++){
        cur="";
        for(int j=0; j<s.length(); j++){
            if(i&(1<<j)){
                cur += s[j];
            }
        }
        if(!cur.length()) continue;
        n=stoi(cur);
        if(sq.count(stoi(cur))) c=min(c, int(s.length()-to_string(n).length()));

    }
    cout<<(c==99999? -1: c);
    return 0;
}
