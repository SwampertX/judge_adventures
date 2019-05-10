#include <bits/stdc++.h>

using namespace std;

int freq[10'001][26];
int t,n,q;
string str;

int main() {
    cin>>t;
    for(int tt=0; tt<t; tt++){
        cin>>n>>q>>str;
        for(int i=1; i<=str.length(); i++){
            for(int j=0; j<26; j++){
                if(j==str[i]-'A') freq[i][j] = freq[i-1][j] +1;
                else freq[i][j] = freq[i-1][j];
            }
        }
        int count(0);
        while(q--){
            int l,r; cin>>l>>r;
            int even(0), odd(0);
            for(int i=0; i<26; i++){
                if((freq[r][i] - freq[l-1][i])%2==0) even++;
                else odd++;
             }
            if(((r-l+1)%2==0 && odd==0) || ((r-l+1)%2==1 && odd==1))
                count++;
        }
        printf("Case #%d: %d\n", tt+1, count);
        for(int i=1; i<n+1; i++)
            fill(freq[i], freq[i]+26, 0);
    }
}

