#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n;
ll h[100005];
ll sum;


int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    sort(h, h+n);
    ll l,r;
    l=h[n-1], r=h[n-1];
    ll rec=0;
    for(int i=n-2; i>=0; i--){
        if(i%2){rec=max(rec,l-h[i]);
            l=h[i];
        }
        else {
            rec=max(rec, r-h[i]); r=h[i];
        }
    }
    cout<<rec;
}
