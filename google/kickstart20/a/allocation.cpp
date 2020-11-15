#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n, a[100001], t, b;
int memo[2][100001];
/* int** memo; */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* memo = (int**) malloc(100001*sizeof(int*)); */
    /* for(int i=0; i<100001; i++) memo[i] = (int*) malloc(100001*sizeof(int)); */

    cin>>t;
    for(int tt=0;tt<t;tt++){
        cin>>n>>b;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        for(int i=0;i<=b;i++) {
            memo[1][i] = i >= a[n-1] ? 1 : 0;
        }

        for(int i=n-2;i>=0;i--){ // house
            for(int j=0;j<=b;j++) {// money_left
                // buy the ith or not
                if (j-a[i] < 0) memo[0][j] = memo[1][j];
                else memo[0][j] = max(memo[1][j-a[i]] + 1, memo[1][j]);
            }
            // first row become second row TODO
            for(int j=0;j<=b;j++) memo[1][j] = memo[0][j];
        }

        for(int i=0;i<2;i++) {
            for(int j=0;j<=b;j++)
                cout<<memo[i][j]<<' ';
            cout<<'\n';
        }

        printf("Case #%d: %d\n",tt, memo[0][b]);
    }

    /* for(int i=0; i<100001; i++) free(memo[i]); */
    /* free(memo); */

    return 0;
}
