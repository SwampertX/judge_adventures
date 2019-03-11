#include <bits/stdc++.h>
const long long INF=2e18;
const long long MOD=10000007;

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

string s;

vector<string> split(string s, char delim){
    stringstream ss(s);
    string item;
    vector<string> ans;
    while(getline(ss, item, delim)){
        if(!item.empty()) ans.push_back(item);
    } return ans;
}
int main(){
/*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
*/
    while(getline(cin, s)){
        for(string x: split(s, ' ')){
            cout<<x<<' ';
        } cout<<'\n';
    }
    return 0;
}

