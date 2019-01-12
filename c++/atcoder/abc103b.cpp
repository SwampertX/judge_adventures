#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

string s,t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>t;
    int l=s.length(), m=0;
    for(int i=0; i<l; i++){
        s=s[l-1]+s.substr(0,l-1);
        if(s==t){
            printf("Yes"); return 0;
        }
    }
    printf("No");
    return 0;
}

