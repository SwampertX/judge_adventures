#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

int n, a[101], m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; while(n--){
        int temp; cin>>temp;
        a[temp]++; m=max(m, a[temp]);
    } cout<<m;
    return 0;
}

