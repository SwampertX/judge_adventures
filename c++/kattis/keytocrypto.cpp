#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

string msg, key, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>msg>>key;
    int l=key.length();
    for(int i=0; i<msg.length(); i++){
        if(i>=key.length()){
            key+=ans[ans.length()-l];
        } char add=msg[i]-key[i]+'A';
        while(int(add)>90) add-=26;
        while(int(add)<65) add+=26;
        ans+=add;
    } cout<<ans;
    return 0;
}
