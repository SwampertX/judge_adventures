#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

int n; ll s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; while(n--){
        int temp; cin>>temp; s+=temp-1;
    } cout<<s;
    return 0;
}
