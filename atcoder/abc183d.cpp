#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, s, t, w, p;
map<int, int> timeUsage;

int main() {
  cin >> n >> w;
  timeUsage.insert(ii(0, 0));
  for (int i = 0; i < n; i++) {
    cin >> s >> t;
    int first = (timeUsage.upper_bound(s) - timeUsage.begin()) - 1;
    /* for (first; first < timeUsage.size(); first++) { */
    /*     int startTime = (timeUsage.begin() + first) */
    /* } */
  }
}
