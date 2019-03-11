#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, temp; vector<int> a;
    cin>>n>>k; for(int i=0; i<n; i++){
        cin>>temp; a.push_back(temp);
    } int diff(0);
    for(int i=1; i<n; i++){
        temp = max(0, k-(a[i]+a[i-1]));
        a[i]+=temp; diff+=temp;
    }
    cout<<diff<<endl;
    for(auto x:a){
        cout<<x<<' ';
    }
}
