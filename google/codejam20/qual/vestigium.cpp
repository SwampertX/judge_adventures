#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int t,n,m[100][100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int tt=0;tt<t;tt++){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        printf("Case #%d: %d %d %d\n",tt);
    }


    return 0;
}
