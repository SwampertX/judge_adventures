#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int a,b,c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    if (abs(c-a)<=d or (abs(b-a)<=d and abs(c-b)<=d)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
