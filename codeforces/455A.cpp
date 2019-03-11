#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; while(cin>>n){
        long long freq[100005], ans[100005];
        memset(freq, 0, 100005);
        int temp; for(int i=0; i<n; i++){
            cin>>temp; freq[temp]++;
        } ans[0]=0; ans[1]=freq[1];
        for(int i=2; i<100001; i++){
            ans[i]=max(ans[i-1], ans[i-2]+i*freq[i]);
        } cout<<ans[100000];
    }
}
