#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;
int main()
{
    ll m, n, a; cin>>n>>m>>a;
    cout << (((n-1)/a+1)*((m-1)/a+1));
    return 0;
}
