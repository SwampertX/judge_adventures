#include <bits/stdc++.h>
using namespace std;

int main(){
    int na, nb; while(cin>>na>>nb){
        int k,m,temp; cin>>k>>m;
        vector <int> a,b;
        for(int i=0; i<na; i++){
            cin>>temp; a.push_back(temp);
        }
        for(int i=0; i<nb; i++){
            cin>>temp; b.push_back(temp);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a[k-1]>=b[nb-m]) cout<<"NO";
        else cout<<"YES";
    }
}
