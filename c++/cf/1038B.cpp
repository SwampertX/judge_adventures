#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n<=2) cout<<"No";
    else {
        cout<<"Yes\n"<<n/2 + n%2 <<' ';
        for(int i=1; i<=n; i+=2){
            cout<<i<<' ';
        } cout<<"\n"<<n/2<<' ';
        for (int i=2; i<=n; i+=2) {
            cout<<i<<' ';
        }
    }
    return 0;
}
