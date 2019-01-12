#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; while(t--){
        int n, temp; vector<int> l,g;
        cin>>n; for(int i=0; i<n; i++){cin>>temp; l.push_back(temp);}
        for(int i=0; i<n; i++){cin>>temp; g.push_back(temp);}
        bool fr(true),bk(true);
        for(int i=0; i<n; i++){
            if(l[i]>g[i]){fr=false;}
            if(l[i]>g[n-i-1]){bk=false;}
            if(!fr && !bk){break;}
        }
        if(fr && bk) cout<<"both"<<endl;
        else if(fr) cout<<"front"<<endl;
        else if(bk) cout<<"back"<<endl;
        else cout<<"none"<<endl;
    }
}
