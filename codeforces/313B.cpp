#include <bits/stdc++.h>
using namespace std;

int main(){
    int dp[100005]; string s;
    cin>>s;
    int len=s.length();
    dp[1]=0;
    for(int i=1; i<len; i++){
        dp[i+1]=dp[i]+int(s[i]==s[i-1]);
    }
    int m, l, r; cin>>m;
    while(m--){
        cin>>l>>r;
        cout<<dp[r]-dp[l]<<endl;
    }
}
