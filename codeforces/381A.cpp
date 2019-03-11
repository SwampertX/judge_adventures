#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; while(cin>>n){
        int c[1000]; for(int i=0; i<n; i++){cin>>c[i];}
        int left(0), right(n-1), a(0), b(0);
        while(left<=right){
            if(c[left]>c[right]){
                a+=c[left]; left++;
            } else {a+=c[right]; right--;}
            if(left>right) break;
            if(c[left]>c[right]){
                b+=c[left]; left++;
            } else {b+=c[right]; right--;}
        }
        cout<<a<<' '<<b;
    }
}
