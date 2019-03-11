#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n,m,c;
set<string> an, am;
string s;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){cin>>s; an.insert(str_hash(s));}
    cin>>m;
    for(int i=0; i<m; i++){cin>>s; am.insert(str_hash(s));}
    for(auto x: an){
        for(auto y:am){
            if(x==y) {c++; am.erase(y);}}
        }
    }
    cout<<c;
    return 0;
}

