#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n; string s;

int main(){
    cin>>n; int one(0), zero(0);
    cin>>s; for(int i=0; i<n; i++){
        if(s[i]=='0') zero++; else one++;
    } if(one)cout<<'1';
    while(zero--)cout<<'0';
    return 0;
}
