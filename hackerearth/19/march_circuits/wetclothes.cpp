#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
int n,m,g;
int t[101], a[100001], memo[101][101];
// memo[time][energy]
int lim = 1;

int run(int energy, int i, int count) {
    if(memo[i][energy] != -1) 
        return memo[i][energy];
    else if(energy==0 || i==n-1) {
        memo[i][energy] = count;
        return count;
    } else {
        int dt = t[i] - t[i-1];
        int sum = 0;
        for(int j=dt; j>=lim; j--) {
            sum += a[dt];
            a[dt] = 0;
        }
        lim = dt;
        memo[i][energy] = max(run(energy-1, i+1, count+sum), run(energy, i+1, count));
        return memo[i][energy];
    }
}

int main(){
    cin>>n>>m>>g;
    for(int i=0; i<n; i++) cin>>t[i];
    for(int i=0; i<m; i++) {
        int temp; cin>>temp;
        a[temp]++;
    }
    for(auto i: memo) fill(i, i+101, -1);
    cout<<run(g, 1, 0);
    return 0;
}
