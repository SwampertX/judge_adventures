#include <bits/stdc++.h>

using namespace std;

string n,a,b;
int t;

int main() {
    cin>>t;
    for(int i=0; i<t; i++) {
        cin>>n;
        for(unsigned int j=0; j<n.length(); j++) {
            char c = n[j];
            if (c=='1' && j==0) {
                int k = 10 + (n[j+1]-'0'); 
                a.push_back('0'+k/2);
                b.push_back('0'+k/2+k%2);
                j++;
            } else if(((string)"789").find(c) == string::npos) {
                a.push_back('0'+(c-'0')/2);
                b.push_back('0'+(c-'0')/2+(c-'0')%2);
            } else {
                a.push_back('0'+2);
                b.push_back(c-2);
            }
        }
        printf("Case #%d: %s %s\n", i+1, a.c_str(), b.c_str());
        a.clear(); b.clear();
    }
}
