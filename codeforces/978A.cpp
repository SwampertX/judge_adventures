#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n, a[1000];
stack<int> b; set<int> have;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=n-1; i>=0; i--){
        if(have.count(a[i])==0) b.push(a[i]),have.insert(a[i]);
    } cout<<b.size()<<'\n';
    while(!b.empty()){
        int x=b.top(); b.pop();
        cout<<x<<' ';
    }
    return 0;
}
