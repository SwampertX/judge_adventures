#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    while(cin>>a>>b){
        int l=a.length();
        for(int i=0; i<l; i++){
            if(a[i]!=b[l-i-1]){
                cout<<"NO"<<endl;
                break;
            } else if(i==l-1){
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
