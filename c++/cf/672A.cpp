#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; while(cin>>n){
        int i=1; string a="";
        while(a.length()<n){
            a+=to_string(i); i++;
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}
