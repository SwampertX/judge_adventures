#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;

const ll INF = 2e18;
const int MOD = 10000007;

string a, b;
char ans[200002];
int al, bl;
short sum, carry;
int pt = 200001;

int main() {
  cin >> a >> b;
  al = a.length();
  bl = b.length();
  int i = 1;
  do {
    int aval = i > al ? 0 : a[al - i] - '0';
    int bval = i > bl ? 0 : b[bl - i] - '0';
    sum = aval + bval + carry;
    carry = sum / 10;
    sum %= 10;
    ans[pt--] = sum + '0';
    i++;
  } while (carry || i <= al || i <= bl);
  printf("%s\n", ans + pt + 1);
  return 0;
}
