#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n,m; while(cin>>n>>m){
        unsigned int a=0, b=0, count=0; bool flag=true;
        for(a; a*a + b<=9999; a++){
                b=0;
            for(b; b*b+a<=9999; b++){
                if(a*a+b==n && b*b+a==m){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}
