#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
//gp_hash_table<int, int> table;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
const int INF = 2e9;
const int MOD = 10000007;

int R, H;
string days;
int dp[50001][1024];

int f(int r, int h) {
  //  cout << r << ' ' << h << endl;
  if (h > H)
    return 0;
  if (r <= 0)
      return -INF;
  /*if (r < R + sqrt(H) || r > R + sqrt(H)) {
      return 0;
      }*/
  int rr = r - R + 512;
  if (dp[h][rr] == -1) {
      if (r==1) {
          dp[h][rr] = f(r, h + r);
      } else if (r==2){
          dp[h][rr] = f(r-1, h + r-1);
      } else {
          dp[h][rr] = max(max(f(r - 1, h + r - 1), f(r, h + r)), f(r + 1, h + r + 1));
      }
    if (days[h - 1] == 's')
      dp[h][rr]++;
  }
  //  cout << dp[r][h] << endl;
  return dp[h][rr];
}

int main() {
    for(int i = 0;i <= 50000;i++) {
        fill(dp[i], dp[i] + 1024, -1);
    }
    cin >> R >> H;

  cin >> days;
  cout << f(R, 0) << endl;
}
