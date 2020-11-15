    #include <bits/stdc++.h>
    using namespace std;


// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash {
//     int operator()(int x) const { return x ^ RANDOM; }
// };
    typedef unsigned long long ull;
    typedef long long ll;
    typedef pair<int, int> ii;
     
    const int INF = 2e9;
    const int MOD = 10000007;
     
    int R, H;
    string days;
    int dp[224][50001];
     
    int f(int r, int h) {
      if (h > H)
        return 0;
      if (r <= 0)
        return -INF;
      if (r*r>h) {
          return 0;
      }
      if (dp[r].find(h) == dp[r].end()) {
          if (r==1) {
              dp[r][h] = f(r, h + r);
          } else if (r==2){
              dp[r][h] = f(r-1, h + r-1);
          } else {
              dp[r][h] = max(max(f(r - 1, h + r - 1), f(r, h + r)), f(r + 1, h + r + 1));
          }
        if (days[h - 1] == 's')
          dp[r][h]++;
      }
      //  cout << dp[r][h] << endl;
      return dp[r][h];
    }
     
    int main() {
      cin >> R >> H;
      cin >> days;
      cout << f(R, 0) << endl;
      /*for(int i = 0;i <= R * 10;i++ ){
          cout<<i<<' '<<dp[i].size()<<'\n';
    }*/
     
    }
