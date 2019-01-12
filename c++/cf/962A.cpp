#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ull n, a[200005];
int main(){
    cin>>n; cin>>a[0];
    for(int i=1; i<n; i++){
        ull temp; cin>>temp;
        a[i]=a[i-1]+temp;
    }
    for(int i=0; i<n; i++){
        if(a[i]*2>=a[n-1]){
            cout<<i+1;
            break;
        }
    }
}
