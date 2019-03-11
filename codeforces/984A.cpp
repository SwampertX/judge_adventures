#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n, a[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; for(int i=0; i<n; i++){
        cin>>a[i];
    } sort(a,a+n);
    cout<<a[(n+1)/2-1];
    return 0;
}

