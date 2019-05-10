#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main() {
    cin>>t; 
    for(int r=0; r<t; r++) {
        printf("Case #%d: ", r+1);
        cin>>n>>s;
        /*
        int i(0), j(1);
        while(i<n && j<n) {
            cout<<s[i]<<s[j]<<' ';
            if(s[i] == s[j]) j++;
            else {
                for(int k=j; k<=i; k--) {
                    cout<<s[k];
                } 
                i = j+1;
                j = i+1;
            }
        }*/
        for(char c: s) {
            cout<<(c=='E'?'S':'E');
        }
        cout<<'\n';
    }
}
