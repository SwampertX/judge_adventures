#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int,int> ii;

ll n; vector<pair<pair<int,int>,int> >  seg;

bool srt(pair<pair<int,int>,int> a, pair<pair<int,int>,int>  b){
    if(a.first.first==b.first.first){return a.first.second>b.first.second;}
    else return a.first.first<b.first.first;
}

int main(){
    cin>>n;
    if(n==1) {printf("-1 -1"); return 0;}
    for(int i=0; i<n; i++){
        int l,r; cin>>l>>r;
        seg.push_back(make_pair(make_pair(l,r),i));
    } sort(seg.begin(), seg.end(), srt);
    for(int i=0; i<n-1; i++){
        if(seg[i].first.second >= seg[i+1].first.second){
            cout<<seg[i+1].second+1<<' '<<seg[i].second+1; break;
        } else if(i==n-2){cout<<-1<<' '<<-1; break;}
    }
    return 0;
}
