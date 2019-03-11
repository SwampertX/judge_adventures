#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

ull t; string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t; while(t--){
        cin>>s; int acc=1; int ans=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='O'){
                ans+=acc; acc++;
            } else {
                acc=1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
