#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first == b.first; }

int main() {
  int a = 5;
  vector<pair<int, int>> vec;
  while (a--) {
    int t1, t2;
    cin >> t1 >> t2;
    vec.push_back(make_pair(t1, t2));
  }
  sort(vec.begin(), vec.end());
  cout << binary_search(vec.begin(), vec.end(), 1, cmp) << endl;
  return 0;
}
