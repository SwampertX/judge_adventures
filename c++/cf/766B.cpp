#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, temp;vector<int> sides;
    cin>>n; for(int i=0; i<n; i++){cin>>temp; sides.push_back(temp);};
    sort(sides.begin(), sides.end());
    for(int iter=n-1; iter>=2; iter--){
        if(sides[iter]-sides[iter-1] <sides[iter-2]){cout<<"YES"; break;}
        else if(iter==2) cout<<"NO";
    }
}
