#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

ll n, w, a[1001];
ll rmin, rmax;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>w>>a[0];
    for(int i=1; i<n; i++){
        cin>>a[i];a[i]+=a[i-1];
    } for(int i=0; i<n; i++){
        rmin=min(a[i], rmin);
        rmax=max(a[i], rmax);
    } if(rmax>w or rmin<-w) cout<<0;
    else{cout<<min(ll(0),rmin)+w-max(ll(0),rmax)+1;}
    return 0;
}
