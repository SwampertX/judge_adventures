#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,temp; vector<int> a,b;
    cin>>n; for(int i=0; i<n; i++){
        cin>>temp; a.push_back(temp);
    } cin>>m; for(int i=0; i<m; i++){
        cin>>temp; b.push_back(temp);
    }
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    int i(0), j(0), res(0);
    while(i<n || j<m){
        if(abs(a[i]-b[j])<=1) {
            i++; j++; res++;
        } else if (a[i]>b[j]) j++;
        else i++;
    }
    cout<<res<<endl;
}
