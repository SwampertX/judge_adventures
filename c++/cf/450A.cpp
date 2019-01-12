#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m; while(cin>>n>>m){
        int index, max(0), a[100];
        for(int i=0; i<n; i++){
            int temp; cin>>temp;
            a[i]=(temp+m-1)/m;
        }
        for(int i=0; i<n; i++){
            if(a[i]>=max) {max=a[i];index=i;}
        }
        cout<<index+1<<endl;
    }
}
