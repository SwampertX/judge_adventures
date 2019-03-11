#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n;
map<ull, ull> a;
ull ans,cur;

int main(){
    cin>>n;
    a[0]++;
    while(n--){
        ull temp; cin>>temp;
        cur+=temp; cur=cur%MOD;
        a[cur]++;
    }
    for(auto x: a){
        ull temp = x.second;
        ans+=temp*(temp-1)/2;
        ans=ans%MOD;
    }
    cout<<ans;
    return 0;
}
