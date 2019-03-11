#include <bits/stdc++.h>
using namespace std;

void submit(){
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);
}

int main() {
    //submit();
    int n; while(cin>>n){
        vector<int> cows, norepeat;
        int prev(0);
        for(int i=0; i<n; i++){
            int temp; cin>>temp;
            cows.push_back(temp);
            if (temp!=prev) norepeat.push_back(temp);
            prev=temp;
        }
        for(int i=1; i<n-1; i++){
            if(norepeat[i]>norepeat[i-1] and norepeat[i]>norepeat[i+1]){//max,to front
                cout<<abs(i+norepeat.begin()-lower_bound(norepeat.begin()+i+1,norepeat.end(), norepeat[i]));
                break;
            } else if(norepeat[i]<norepeat[i-1] and norepeat[i]<norepeat[i+1]){
                cout<<abs(i+norepeat.begin()-lower_bound(norepeat.begin(),norepeat.end(), norepeat[i]));
                break;
            }
        }
}
}
