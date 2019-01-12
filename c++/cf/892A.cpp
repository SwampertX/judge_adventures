#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    int n; while(cin>>n){
        ull asum(0),a,b1(0),b2(0),b;
        for(int i=0; i<n; i++){
            cin>>a;
            asum+=a;
        } for(int i=0; i<n; i++){
            cin>>b;
            if(b>=b1){b2=b1; b1=b;}
            else if (b>b2){b2=b;}
        }
        if(asum>b1+b2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
