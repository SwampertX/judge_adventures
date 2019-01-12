#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.ignore(INT_MAX);
    string str;
    getline(cin, str);
    vector<int> no;
    for(auto x=str.begin(); x!=str.end(); x++){
        int temp; cin>>temp; no.push_back(temp);
    }
    sort(no.begin(),no.end()); int s=no.size();
    for(int i=0; i<s; i++){
        if(i!=s-1)cout<<no[i]<<'+';
        else cout<<no[i];
    }
}
