#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 2e9;
const int MOD = 10000007;

int R, H;
string days;
#define SHIFT 32
cc_hash_table<unsigned short, unsigned short> dp[50001 * SHIFT];

int f(int r, int h) {
  //  cout << r << ' ' << h << endl;
  if (h > H)
    return 0;
  if (r <= 0)
    return -INF;
  //if (r * r > h) {
  //    return f(sqrt(h) + 1, r);
  //}
  int rr = r * SHIFT + h % SHIFT;
  int hh = h / SHIFT;
  if (dp[rr].find(hh) == dp[rr].end()) {
      if (rr==1) {
          dp[rr][hh] = f(r, h + r);
      } else if (r==2){
          dp[rr][hh] = f(r-1, h + r-1);
      } else {
          dp[rr][hh] = max(max(f(r - 1, h + r - 1), f(r, h + r)), f(r + 1, h + r + 1));
      }
    if (days[h - 1] == 's')
      dp[rr][hh]++;
  }
  //  cout << dp[r][h] << endl;
  return dp[rr][hh];
}

int main() {
  cin >> R >> H;
  cin >> days;
  cout << f(R, 0) << endl;
  /*for(int i = 0;i <= R * 10;i++ ){
      cout<<i<<' '<<dp[i].size()<<'\n';
}*/

}
