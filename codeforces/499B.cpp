#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n,m;
map<string,string> stlg;

int main(){
    cin>>n>>m;
    while(m--){
        string s1,s2;cin>>s1>>s2;
        stlg[s1]=(s1.length()<=s2.length()?s1:s2);
    }
    while(n--){
        string s; cin>>s;
        cout<<stlg[s]<<' ';
    }
    return 0;
}
