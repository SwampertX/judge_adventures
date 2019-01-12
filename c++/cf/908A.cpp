#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF=2e18;
const int MOD=10000007;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s; int a = 0;
    string r = "aeiou13579";
    for(int i=0; i<s.length(); i++) {
        for(int j=0; j<r.length(); j++) {
            if(s[i]==r[j]) {
                a++; break;
            }
        }
    }
    cout<<a;
    return 0;
}
