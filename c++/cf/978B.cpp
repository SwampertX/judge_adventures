#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n; string s;
int c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for(auto x:s){
        if(x=='x'){
            if(c>=2) d++;
            c++;
        } else c=0;
    } cout<<d;
    return 0;
}
