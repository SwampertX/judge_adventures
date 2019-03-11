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
    cin >> n;
    if (n % 3 == 2) {
        printf("1 2 %d", n-3);
    } else printf("1 1 %d", n-2);
    return 0;
}
