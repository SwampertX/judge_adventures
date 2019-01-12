#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n,k;
vector<int> a;

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int temp; cin>>temp;
        a.push_back(temp);
    } sort(a.begin(), a.end());
    if(k==0){cout<<(a[0]>1?1:-1);}
    else if(upper_bound(a.begin(), a.end(), a[k-1])==a.begin()+k){
        cout<<a[k-1];
    } else cout<<-1;
    return 0;
}
