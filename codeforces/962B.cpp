#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int n, a, b; string s;
int d,e,len;

int main(){
    cin>>n>>a>>b>>s;
    for(int i=0; i<n; i++){
        if(s[i]=='*'){
          d+=len/2;
          e+=len%2;
          len=0;
        } else len++;
    }
    d+=len/2, e+=len%2;
    cout<<min(d,a)+min(d,b)+min(e, max(a-d,0)+max(b-d,0));
}
