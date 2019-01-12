#include <bits/stdc++.h>
using namespace std;

int main() {
    int temp; string str;
    vector<int> no;
    cin>>str; for(auto x: str){if(x!='+') no.push_back(x-'0');}
    sort(no.begin(),no.end()); int s=no.size();
    for(int i=0; i<s; i++){
        if(i!=s-1)cout<<no[i]<<'+';
        else cout<<no[i];
    }
}
