#include <bits/stdc++.h>
#define INF 2e18
using namespace std;

typedef unsigned long long ll;

int n;
vector<ll> h;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        ll temp; cin>>temp; h.push_back(temp);
    } int l=0, r=1, rec(0);
    while(r<n){
        if(h[r]>=h[l]){
            rec=max(rec, r-l);
            l=r;
        } r++;
    } r=n-1; l=n-2;
    while(l>=0){
        if(h[r]<=h[l]){
            rec=max(rec, r-l);
            r=l;
        } l--;
    }
    cout<<rec;
    return 0;
}
