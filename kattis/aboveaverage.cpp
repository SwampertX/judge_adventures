#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

double c,n,stu[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>c; while(c--){
        cin>>n;
        double avg=0, pct=0;
        for(int i=0; i<n; i++){
            cin>>stu[i];
            avg+=stu[i]/n;
        }
        for(int i=0; i<n; i++){
            if(stu[i]>avg){pct+=100.0/n;}
        }
        cout<<setprecision(3)<<fixed<<pct<<"%\n";
    }
    return 0;
}

