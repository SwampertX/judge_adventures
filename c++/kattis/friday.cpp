#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

int t,m,d,days[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t; while(t--){
        cin>>d>>m;
        for(int i=0; i<m; i++) cin>>days[i];
        int diw=0, rec=0;
        for(int i=0; i<m; i++){
            if((diw+12)%7==5 && days[i]>=13) rec++;
            diw+=(days[i]%7); diw=diw%7;
        }
        cout<<rec<<'\n';
    }
    return 0;
}
