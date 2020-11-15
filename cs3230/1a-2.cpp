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
int dp[500][50001];

int f(int r, int h) {
  //  cout << r << ' ' << h << endl;
  if (h > H)
    return 0;
  if (h == H)
    return days[h - 1] == 's';
  if (r <= 0)
      return -INF;
  /*if (r < R + sqrt(H) || r > R + sqrt(H)) {
      return 0;
      }*/
  int rr = r - int(sqrt(R)) + 240;
  if (dp[rr][h] == -1) {
    if (r==1) {
      dp[rr][h] = f(r, h + r);
    } else if (r==2){
      dp[rr][h] = f(r-1, h + r-1);
    } else {
      dp[rr][h] = max(max(f(r - 1, h + r - 1), f(r, h + r)), f(r + 1, h + r + 1));
    }
    if (days[h - 1] == 's')
      dp[rr][h]++;
  }
  //  cout << dp[r][h] << endl;
  return dp[rr][h];
}

int main() {
  for(int i = 0;i < 490;i++) {
    fill(dp[i], dp[i] + 50000, -1);
  }
  cin >> R >> H;

  cin >> days;
  cout << f(R, 0) << endl;
}
