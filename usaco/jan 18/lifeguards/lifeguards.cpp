#include <bits/stdc++.h>
using namespace std;

void submit(){
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
}

int main(){
    submit();
    int n; while(cin>>n){
        vector<pair<int,int>> cows;
        for(int i=0; i<n; i++){
            int t1,t2; cin>>t1>>t2;
            cows.push_back(make_pair(t1,t2));
        }
        sort(cows.begin(),cows.end());
        int m(0);
        for(int iter=0; iter<n; iter++){
        int current(0), end(0);
            for (int i=0; i<n; i++){
                if(i==iter) continue;
                if(cows[i].second<=end) continue;
                current+=cows[i].second - max(cows[i].first, end);
                end=cows[i].second;
            }
            m=max(m,current);
        }
        cout<<m;
    }
}
