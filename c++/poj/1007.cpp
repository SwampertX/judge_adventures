#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<pair<int, string> > o;
    for(int i=0; i<m; i++){
        int temp(0); string s; cin>>s;
        for(int j=0; j<n-1; j++){
            int t=int(s[j]) - int(s[j+1]);
            temp+=max(0, t);
            cout<<temp<<endl;
        } o.push_back(make_pair(temp,s));
    }
    sort(o.begin(),o.end());
    for(auto x:o) cout<<x.first<<' '<<x.second<<endl;
}
