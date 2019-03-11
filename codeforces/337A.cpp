#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; while(cin>>n>>m){
        vector<int> puz;
        for(int i=0; i<m; i++){
            int temp; cin>>temp; puz.push_back(temp);
        }
        sort(puz.begin(),puz.end());
        int diff(1000),temp;
        for(int i=0; i<m-n+1; i++){
            temp=puz[i+n-1]-puz[i];
            diff=min(diff,temp);
        }
        cout<<diff;
    }
}
