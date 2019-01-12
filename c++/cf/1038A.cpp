#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

int n, k;
string s;
int c[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>s;
    for(int i = 0; i < n; i++){
        int ind; ind = s[i] - 65;
        c[ind]++;
    }
    sort(c,c+k);
    cout<<k*c[0];
    return 0;
}

