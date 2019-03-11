#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n; map<int,ull> id_a;
vector<pair<ii, int> > fac_id;

bool srt(pair<ii,int> a, pair<ii,int>b){
    if(a.first.first == b.first.first) return a.first.second>b.first.second;
    else return a.first.first < b.first.first;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        ull temp; cin>>temp;
        id_a[i]=temp;
        fac_id.push_back({{0,0},i});
        while(temp%2==0){temp/=2; fac_id[i].first.first++;}
        while(temp%3==0){temp/=3; fac_id[i].first.second++;}
    } sort(fac_id.begin(),fac_id.end(),srt);
    for(auto x: fac_id){
        int id=x.second;
        cout<<id_a[id]<<' ';
    }
    return 0;
}
