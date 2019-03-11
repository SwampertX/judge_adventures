#include <bits/stdc++.h>
using namespace std;
bool is_eq(string a, string b){
    int len=a.length();
    if(a==b) return true;
    else if (len%2==1) return false;
    else{
        string a1, a2, b1, b2;
        a1= a.substr(0,len/2);
        a2= a.substr(len/2,len/2);
        b1= b.substr(0,len/2);
        b2= b.substr(len/2,len/2);
        if (is_eq(a1,b1) && is_eq(a2,b2)) return true;
        if (is_eq(a1,b2) && is_eq(a2,b1)) return true;
        return false;
    }
}
int main() {
    string a,b; while(cin>>a>>b){
        if(is_eq(a,b)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
