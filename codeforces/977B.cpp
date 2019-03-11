#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n; string s;
map<string,int> p;

int main(){
    cin>>n>>s; int m=0;
    string rec;
    for(int i=0; i<n; i++){
        p[s.substr(i,2)]++;
        int x=p[s.substr(i,2)];
        if(x>m) rec=s.substr(i,2);
        m=max(m,x);
    } cout<<rec;
    return 0;
}
