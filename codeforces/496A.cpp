#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; while(cin>>n){
        int a[101]; for(int i=0; i<n; i++){
            cin>>a[i];
        } int dis(1005);
        for(int i=1; i<n-1; i++){
            int record(0);
            for(int j=0; j<n-1; j++){
                if(j==i-1) {
                    record=max(record,a[j+2]-a[j]);
                    j++;
                } else{
                    record=max(record,a[j+1]-a[j]);
                }
            }
            dis=min(dis,record);
        }
        cout<<dis;
    }
}
