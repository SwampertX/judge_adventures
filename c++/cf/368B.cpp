#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n,m;
int a[100000];
set<int> b;
int c[100000];
//c[i] is the ans for given i

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=n-1; i>=0; i--){
        b.insert(a[i]);
        c[i]=b.size();
    }
    while(m--){
        int l; cin>>l;
        cout<<c[l-1]<<endl;
    }
    return 0;
}
