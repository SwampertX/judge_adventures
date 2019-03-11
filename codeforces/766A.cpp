#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

string s1,s2;

int main(){
    cin>>s1>>s2;
    if(s1==s2) cout<<-1;
    else cout<<max(s1.length(),s2.length());
    return 0;
}
